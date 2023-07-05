package Modelo;

import com.mongodb.MongoException;
import com.mongodb.client.AggregateIterable;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoCursor;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoIterable;
import com.mongodb.client.model.Aggregates;
import static com.mongodb.client.model.Aggregates.match;
import com.mongodb.client.model.Filters;
import static com.mongodb.client.model.Filters.and;
import static com.mongodb.client.model.Filters.eq;
import static com.mongodb.client.model.Filters.gte;
import static com.mongodb.client.model.Filters.in;
import static com.mongodb.client.model.Filters.lte;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import javax.swing.JOptionPane;
import org.bson.Document;
import org.bson.conversions.Bson;

public class TweetDAO 
{
    Conexion conexion = null; 
    MongoDatabase db = null;
    
    public TweetDAO(Conexion c)
    {
        this.conexion = c;
        db = c.getConexion().getDatabase("Twitter");
    }
    
    //1.- Función que devuelve el número de tweets almacenados en la colección
    public int numTweets(String coleccion) throws MongoException
    {
        MongoCollection colec = db.getCollection(coleccion);
        
        return (int) colec.countDocuments();
    }    
    
    //2.1.- Función que devuelve la fecha más reciente de todos los tweets almacenados
    public Date fechaMasReciente(String coleccion) throws MongoException
    {
        Date fecha = null;
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document sort = new Document("$sort", new Document("created", -1));
        Document project = new Document("$project", new Document("_id",0).append("created", 1));
        Document limit = new Document("$limit",1);
        
        List<Document> pipeline = Arrays.asList(sort, project, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            
            fecha = document.getDate("created");
        }
        
        return fecha;
    }
    
    //2.2.- Función que devuelve la fecha menos reciente de todos los tweets almacenados
    public Date fechaMenosReciente(String coleccion) throws MongoException
    {
        Date fecha = null;
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document sort = new Document("$sort", new Document("created", 1));
        Document project = new Document("$project", new Document("_id",0).append("created", 1));
        Document limit = new Document("$limit",1);
        
        List<Document> pipeline = Arrays.asList(sort, project, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            
            fecha = document.getDate("created");
        }
        
        return fecha;
    }
    
    //3.- Función que devuelve el nombre del usuario con más seguidores y el número de seguidores
    public Tweet usuarioConMasSeguidores(String coleccion) throws MongoException
    {
        Tweet tweet = new Tweet();
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document sort = new Document("$sort", new Document("followers",-1));
        Document project = new Document("$project", new Document("_id",0).append("username", 1).append("followers", 1));
        Document limit = new Document("$limit", 1);
        
        List<Document> pipeline = Arrays.asList(sort, project, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            
            tweet.setUsername(document.getString("username"));
            tweet.setFollowers(document.getInteger("followers"));
        }
        
        return tweet;
    }
    
    //4.- Función que devuelve a los 5 usuarios más mencionados junto con su frecuencia en todos los tweets
    public List<Entry<String, Integer>> usuariosMasMencionados(String coleccion) throws MongoException
    {
        Map<String, Integer> map = new HashMap<String, Integer>();
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document project = new Document("$project", new Document("_id",0).append("text", 1));
        
        List<Document> pipeline = Arrays.asList(project);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            String tweet = document.getString("text");
            String tokens[] = tweet.split("\\s+|\n");
            
            for(int i=0; i<tokens.length; i++)
            {
                if(tokens[i].startsWith("@") && tokens[i].length()>1)
                {  
                    if(map.containsKey(tokens[i]))
                    {
                        map.put(tokens[i], map.get(tokens[i])+1);
                    }
                    else
                    {
                        map.put(tokens[i], 1);
                    }
                }
            }            
        }
        
        List<Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort(Entry.comparingByValue());
        
        List<Entry<String, Integer>> ret = new ArrayList<Entry<String, Integer>>();
        
        ret.add(list.get(list.size()-1));
        ret.add(list.get(list.size()-2));
        ret.add(list.get(list.size()-3));
        ret.add(list.get(list.size()-4));
        ret.add(list.get(list.size()-5));
        
        return ret;  
    }
    
    //5.- Función que devuelve los 5 #Hashtags más utilizados en los tweets con su frecuencia
    public ArrayList<String> hashtagsMasUtilizados(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        ArrayList<String> ret = new ArrayList<String>(); 
        
        Document unwind = new Document("$unwind", new Document("path", "$hashtags"));
        Document group = new Document("$group", new Document("_id", "$hashtags.text").append("frecuencia", new Document("$sum", 1)));
        Document sort = new Document("$sort", new Document("frecuencia", -1));
        Document limit = new Document("$limit", 5);
        
        List<Document> pipeline = Arrays.asList(unwind, group, sort, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            ret.add("#" + document.getString("_id") + " aparece " + document.getInteger("frecuencia") + " veces");
        }
        
        return ret; 
    }
    
    //6.- Función que devuelve el número de idiomas diferentes utilizados en los tweets almacenados en la colección
    public int numeroIdiomasDiferentes(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        int numIdiomasDiferentes = 0; 
        
        Document group = new Document("$group", new Document("_id", "$language"));
        Document count = new Document("$count", "Numero");
        
        List<Document> pipeline = Arrays.asList(group, count);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            numIdiomasDiferentes = document.getInteger("Numero");
        }
        
        return numIdiomasDiferentes; 
    }
    
    //7.- Función que devuelve los 5 idiomas más frecuentes en los tweets junto con su frecuencia
    public ArrayList<String> idiomasMasFrecuentes(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        ArrayList<String> ret = new ArrayList<String>();
        
        Document group = new Document("$group", new Document("_id", "$language").append("count", new Document("$sum", 1)));
        Document sort = new Document("$sort", new Document("count",-1));
        Document limit = new Document("$limit", 5);
        
        List<Document> pipeline = Arrays.asList(group, sort, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            ret.add(document.getString("_id") + ". Utilizado en " + document.getInteger("count") + " tweets");
        }
        
        return ret;
    }
    
    //8.- Función que devuelve los número de tweets que son RT's
    public int numeroDeRT(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        int numeroRT = 0;
        
        Document project = new Document("$project", new Document("_id",0).append("text", 1));

        List<Document> pipeline = Arrays.asList(project);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            if(document.getString("text").startsWith("RT @"))
            {
                numeroRT++;
            }
        }
        
        return numeroRT; 
    }
    
    //9.- Función que devuelve el número de usuario diferentes de los cuales se almacenan tweets en la colección
    public int numeroDeUsuariosDiferentes(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        int nUsuariosDiferentes = 0;
        
        Document group = new Document("$group", new Document("_id", "$username"));
        Document count = new Document("$count", "Numero");
        
        List<Document> pipeline = Arrays.asList(group, count);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            
            nUsuariosDiferentes = document.getInteger("Numero");
        }
        
        return nUsuariosDiferentes;
    }
    
    //10.- Función que devuelve a los usuarios que más tweets tienen almacenados en la colección junto con su frecuencia
    public ArrayList<String> usuariosFrecuenciaTweets(String coleccion) throws MongoException
    {
        MongoCollection<Document> collection = db.getCollection(coleccion);
        ArrayList<String> ret = new ArrayList<String>();
        
        Document group = new Document("$group", new Document("_id", "$username").append("count", new Document("$sum", 1)));
        Document sort = new Document("$sort", new Document("count",-1));
        Document limit = new Document("$limit", 5);
        
        List<Document> pipeline = Arrays.asList(group, sort, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            ret.add("@" + document.getString("_id") + " con " + document.getInteger("count") + " tweets");
        }
        
        return ret;
    }
    
    //Función para recuperar toda la información de una tabla
    public ArrayList<Tweet> listaTweets(String coleccion, int numeroMinSeguidores, int numeroMaxSeguidores, String usuario, String hashtag, String palabra, List<String> idiomas, boolean volcar, String nombreNuevaColeccion) throws MongoException
    {   
        ArrayList<Tweet> lTweets = new ArrayList<Tweet>();
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        //Único campo obligatorio en la consulta: Rango de seguidores
        Bson criterio1 = match(and(gte("followers", numeroMinSeguidores), lte("followers", numeroMaxSeguidores))); 
        
        //Búsqueda por usuario
        Bson criterio2 = match(eq("username", usuario));
        
        //Búsqueda por hashtag
        Bson criterio3 = match(eq("hashtags.text", hashtag));
        
        //Búsqueda por palabra o expresión específica dentro del campo texto
        Bson criterio4 = Aggregates.match(Filters.text(palabra));
        
        //Búsqueda por idioma/s
        Bson criterio5 = match(in("language", idiomas));
               
        List<Bson> pipeline = new ArrayList<>();
        
        if(!palabra.equals("")) // Hacemos esta comprobación primero porque las búsquedas por palabras van primero
            pipeline.add(criterio4);
        
        pipeline.add(criterio1);
        
        if(!usuario.equals("")) 
            pipeline.add(criterio2);
        
        if(!hashtag.equals(""))
            pipeline.add(criterio3);
        
        if(idiomas.size()>0)
            pipeline.add(criterio5);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            
            Tweet tweet = new Tweet(document.getString("id"),
                    document.getString("username"),
                    document.getInteger("followers"), 
                    document.getString("text"), 
                    document.getString("language"),
                    document.getDate("created"));
            
            lTweets.add(tweet);
        }
        
        if(volcar && !nombreNuevaColeccion.equals(""))
        {
            MongoCollection<Document> newCollection = db.getCollection(nombreNuevaColeccion);
            newCollection.insertMany(result.into(new ArrayList<Document>()));
            JOptionPane.showMessageDialog(null, "La colección " + nombreNuevaColeccion +  " ha sido creada correctamente", "", 1);
        }
        
        return lTweets;
    }
    
    //Funcion para obtener las colecciones que tiene la base de datos Twitter
    public MongoIterable<String> nombreColecciones() throws MongoException
    {
        return db.listCollectionNames();
    }
    
    
    //Función que devuelve el listado de idiomas de la colección, sirve para rellenar el JList de idiomas
    public ArrayList<String> listadoIdiomas(String coleccion) throws MongoException
    {
        ArrayList<String> idiomas = new ArrayList<String>();
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document group = new Document("$group", new Document("_id", "$language"));
        Document sort = new Document("$sort", new Document("_id",1));
        
        List<Document> pipeline = Arrays.asList(group, sort);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        while(result2.hasNext())
        {
            Document document = result2.next();
            
            idiomas.add(document.getString("_id"));
        }
        
        return idiomas;
    }
    
    //Función que devuelve el tweet del usuario con menos seguidores de la colección
    public Tweet usuarioConMenosSeguidores(String coleccion) throws MongoException
    {
        Tweet tweet = new Tweet();
        MongoCollection<Document> collection = db.getCollection(coleccion);
        
        Document sort = new Document("$sort", new Document("followers",1));
        Document limit = new Document("$limit", 1);
        
        List<Document> pipeline = Arrays.asList(sort, limit);
        
        AggregateIterable<Document> result = collection.aggregate(pipeline);
        
        MongoCursor<Document> result2 = result.iterator();
        
        if(result2.hasNext())
        {
            Document document = result2.next();
            
            tweet.setId(document.getString("id"));
            tweet.setUsername(document.getString("username"));
            tweet.setFollowers(document.getInteger("followers"));
            tweet.setText(document.getString("text"));
            tweet.setLanguage(document.getString("language"));
            tweet.setDate(document.getDate("created"));
        }
        
        return tweet;
    }
}
