using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

interface IStore
{
    bool save(String id, String message);
    String read(String id);
    FileInfo getFileInfo(String name);
}
interface IFileLocator
{
    FileInfo GetFileInfo(string name);
    bool Save(string path, string message);
    string Read(string path);
    bool save(String id, String message);
    String read(String id);
}
interface ICacheStore
{
    bool AddOrUpdate(String id, String message);
    String GetOrAdd(String id, String message);
}
interface LoggerStore
{
    string Read(string path);
}
namespace ConsoleApplication4
{
    class FileStorage:IStore, IFileLocator
    {
        private readonly Dictionary<string, string> cache;

        virtual public DirectoryInfo WorkingDirectory { get; private set; }

        public FileStorage(DirectoryInfo workingDirectory)
        {
            if (workingDirectory == null)
            {
                throw new ArgumentNullException("workingDirectory");
            }

            if (!workingDirectory.Exists)
            {
                throw new ArgumentNullException("Boo", "workingDirectory");
            }

            this.WorkingDirectory = workingDirectory;
            this.cache = new Dictionary<string, string>();
        }
        virtual public FileInfo GetFileInfo(string name)
        {
            return new FileInfo(Path.Combine(WorkingDirectory.FullName, name + ".txt"));
        }
        virtual public bool Save(string path, string message)
        {
            Cache c = new Cache(WorkingDirectory.Name);
            return c.Save(path,message);
        }
        virtual public string Read(string path)
        {
            Logger logger = new Logger(WorkingDirectory.Name);
            return logger.Read(path);
        }
        public bool save(String id, String message)
        {
            return this.Save(id,message); //Return true if exists false if not (but create it)
        }
        public String read(String id)
        {
            return this.Read(id);
        }
        public FileInfo getFileInfo(String name)
        {
            return this.GetFileInfo(name);
        }
    }
    class Cache:ICacheStore
    {
        private readonly Dictionary<string, string> cache;
        private DirectoryInfo directoryInfo;
        private FileStorage fileStorage;
        public Cache(String dir)
        {
            this.directoryInfo = new DirectoryInfo(dir);
            this.fileStorage = new FileStorage(directoryInfo);
            this.cache = new Dictionary<string, string>();
        }
        virtual public bool Save(string path, string message) //Cache
        {
            Console.WriteLine("INFO: Saving message {0}.", path);
            var file = fileStorage.GetFileInfo(path);
            File.WriteAllText(file.FullName, message);
            bool ret = false;

            if (cache.ContainsKey(path))
            {
                cache[path] = message;
                ret = true;
            }
            else
            {
                cache.Add(path, message);
            }

            Console.WriteLine("INFO: Saved messagee {0}.", path);
            return ret; 
        }
        public bool AddOrUpdate(String id, String message)
        {
            return this.Save(id,message);
        }
        public String GetOrAdd(String id, String message)
        {
            MessageStorage messageStorage = new MessageStorage();

            if(messageStorage.GetLogger(id).Read(id).Equals(""))
                return "";
            else
            return message;
        }
    }
    class Logger:LoggerStore
    {
        private readonly Dictionary<string, string> cache;
        private DirectoryInfo directoryInfo;
        private FileStorage fileStorage;
        public Logger(String dir) //Constructor
        {
            this.directoryInfo = new DirectoryInfo(dir);
            this.fileStorage = new FileStorage(directoryInfo);
            this.cache = new Dictionary<string, string>();
        }
        virtual public string Read(string path) //Register
        {
            string message;
            Console.WriteLine("DEBUG: Readline message {0}.", path);
            var file = fileStorage.GetFileInfo(path);
            if (!file.Exists)
            {
                Console.WriteLine("DEBUG: No message {0} found.", path);
                return "";
            }

            if (!cache.ContainsKey(path))
            {
                cache.Add(path, File.ReadAllText(file.FullName));
            }

            message = cache[path];
            Console.WriteLine("DEBUG: Returning message {0}.", path);
            return message;
        }
    }
    class DataManipulator
    {
        MessageStorage messageStorage;
        Cache cache;
        Logger logger;
        public DataManipulator()
        {
            this.messageStorage = new MessageStorage();
        } 
        public void execute(DirectoryInfo directoryInfo, String dir)
        {
            messageStorage.GetFileStorage(directoryInfo);
            this.cache = messageStorage.GetCache(dir);
            this.logger = messageStorage.GetLogger(dir);
        }
    }
    class MessageStorage
    {
        virtual public FileStorage GetFileStorage(DirectoryInfo directoryInfo)
        {
            return new FileStorage(directoryInfo);
        }
        virtual public Cache GetCache(String dir)
        {
            return new Cache(dir);
        }
        virtual public Logger GetLogger(String dir)
        {
            return new Logger(dir);
        }
    }
    abstract class SqlStore:IStore
    {
        MessageStorage messageStorage = new MessageStorage();
        public bool save(String id, String message)
        {
            return messageStorage.GetCache(id).Save(id,message);
        }
        public String read(String id)
        {
            return messageStorage.GetLogger(id).Read(id);
        }
        abstract public FileInfo getFileInfo(String name);
    }
    class Test
    {
        static void Main(String []args)
        {
            Console.WriteLine("Successful compilation ");
        }
    }
}