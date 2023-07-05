En la práctica, cada servidor del conjunto de réplica estará en un ordenador independiente.

En este ejercicio, para aprender a crear y gestionar un conjunto de réplica vamos a considerar que los diferentes servidores son procesos que se están ejecutando en el mismo equipo. 

Previamente debemos tener: 
- Una carpeta de datos por cada servidor de la réplica
- Un puerto para cada servidor
- Un nombre único para el conjunto de réplica

El funcionamiento general será: 
- Iniciar tantos servidores como elementos tenga el conjunto de réplica
- Crear la réplica, indicando que todos los servidores están en el mismo conjunto

Existen diversas formas de crear un conjunto de réplica. Por ejemplo, se pueden crear todos los nodos en el mismo momento, ir añadiéndolos a medida que se necesiten, etc. 

En este ejercicio crearemos un conjunto de réplica con la configuración básica, es decir, formado por tres nodos de los cuales uno actuará como primario y los otros dos como secundarios. 

1. Lo primero que hacemos es crear los directorio/carpetas donde se van a guardar los datos. En este ejemplo, las carpetas se están creando en la ruta **/usr/local/var/mongodb**
   ```terminal
    mkdir replicaSet
    cd replicaSet
    mkdir rs0
    mkdir rs1
    mkdir rs2
    ```
2. Lanzamos el servicio correspondiente al primer nodo. 
```terminal
mongod --replSet miReplicaSet --dbpath /usr/local/var/mongodb/replicaSet/rs0 --logpath /usr/local/var/mongodb/replicaSet/rs0/log.rs0 --bind_ip 127.0.0.1,localhost --port 27000 --fork --logappend --oplogSize 50
```
   Breve explicación de los parámetros utilizados:
   - **replSet.** Indica el nombre del conjunto de réplica en el que se va a iniciar la instancia.
   - **dbpath.** El directorio donde se almacenarán los datos (debe existir).
   - **logpath <ruta/fichero>.** Fichero en el que se almacenará el log de lo que que ocurra en el servicio.
   - **bind_ip.** Dirección ip o nombre del servidor.
   - **port.** Puerto (si no se especifica, MongoDB utiliza el puerto 27017).
   - **fork.** Comando para que el servicio se ejecute en segundo plano (*background*).
   - **logappend.** Indica que no se vacíe el fichero de log en caso de que ya exista (opcional).
   - **oplogSize <tamaño>.** Se utiliza en entornos de desarrollo para limitar el tamaño del fichero de operaciones log. Este fichero es el que se usa para llevar a cabo la replicación.
3. Levantamos los otros dos nodos.
   - Se puede comprobar, con **ps -ef | grep mongo**, que los servicios están activos de manera individual porque aún no se ha configurado el conjunto de réplica.

    ```terminal
    mongod --replSet miReplicaSet --dbpath /usr/local/var/mongodb/replicaSet/rs1 --logpath /usr/local/var/mongodb/replicaSet/rs1/log.rs1 --bind_ip 127.0.0.1,localhost --port 27001 --fork --logappend --oplogSize 50
    ```

    ```terminal
    mongod --replSet miReplicaSet --dbpath /usr/local/var/mongodb/replicaSet/rs2 --logpath /usr/local/var/mongodb/replicaSet/rs2/log.rs2 --bind_ip 127.0.0.1,localhost --port 27002 --fork --logappend --oplogSize 50
    ```
4. Nos conectamos al primero de los nodos por el puerto especificado. Podemos comprobar, mediante el comando **rs.config()**, que el conjunto todavía no se ha iniciado. 

    ```terminal
    mongosh --port 27000
    > rs.config()
    MongoServerError: no replset config has been received
    ```
5. El comando **rs.initiate()** inicializa el conjunto de réplica con el nodo al que estamos conectados. Como parámetro se le psaa un objeto con los datos de configuración. Este fichero debe ser un documento con un campo **_id** con el nombre del conjunto de réplica y un campo **members**, que será un array con tantos elementos como miembros haya en la réplica. A su vez, cada elemento debe tener un campo **_id** único y un campo **host** con el nombre o dirección del equipo donde está ubicado.

    ```terminal
    config = { _id: "miReplicaSet", members: [ { _id: 0, host: "127.0.0.1:27000"}, {_id: 1, host: "127.0.0.1:27001"}, {_id: 2, host: "127.0.0.1:27002"} ] }
    ```
6. Volvemos a ejecutar **rs.config()** para comprobar que el conjunto se ha creado correctamente.
7. El estado del conjunto de réplica se puede comprobar con el comando **rs.status()** (se han omitido varias líneas y se han dejado las más significativas)
8. Si todo ha ido bien, podremos conectarnos desde nuestros entornos preferidos (Compass, Studio3T, etc.)
9.  Una vez que ya está configurado y activo el conjunto de réplica, vamos a probar cómo se produce la réplica de datos entre todos los nodos que forman parte de él. Lo primero que debemos hacer es crear una colección (se puede hacer desde Compass, Studio3T, terminal, etc.)
10. Una vez insertados los datos en el nodo primario, vamos a comprobar que se han replicado en un nodo secundario. Nos debe salir un error. **(este ejercicio y los siguientes deben hacerse desde el mongosh del terminal, conectándonos al nodo secundario mediante mongosh -port 27001)**
11. El error se produce porque, por defecto, los nodos secundarios en un conjunto de réplica no admiten operaciones ni de escritura ni de lectura. Todas las operaciones debe realizarse siempre sobre el nodo principal. Sin embargo, podemos activar el permiso para realizar operaciones de lectura sobre un nodo secundario. Para ello utilizaremos la función **db.getMongo().setReadPref('secondary')** en la conexión del nodo secundario. La invocación de esta función significa que le estamos indicando a MongoDB que somos conscientes de que etsamos trabajando sobre un nodo secundario. 
12. Vamos a probar qué ocurre cuando el nodo primario se "cae" para comprobar que, de forma automática, uno de los nodos secundarios toma el papel de primario y empieza a admitir operaciones de lectura y escritura.
13. Paramos el nodo primario para simular una caída, pérdida de conexión, etc.
14. Si nos conectamos con **mongosh -port 27001**, se puede commprobar que ha pasado a primario. 
15. Si volvemos a lanzar el nodo del puerto 27000 se puede comprobar que pasa a ser secundario (lo indica el prompt y también se puede ver a través de **rs.status()**)
16. Para volver a la configuración original, "caemos" los tres procesos y los volvemos a lanzar en el orden deseado. 
17. Comprobemos que no se puede escribir en un nodo secundario. 
18. Comprobemos ahora que el conjunto de réplica está sincronizado. Eliminamos 20 elementos de la colección.
19. Se puede modificar la configuración del conjunto en cualquier momento. Supongamos que queremos que el tercer miembro del conjunto réplica quede oculto. 
20. Ahora vamos a configurar uno de los nodos secundarios como nodo retardado y comprobemos que tarda 5 minutos en actualizar los datos del nodo primario.
21. Se puede forzar "en caliente" a que un nodo pase a ser primario. 