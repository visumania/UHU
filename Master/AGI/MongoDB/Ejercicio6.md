**1. Crear un usuario "administrador" con login "super" y el password que queráis. Al menos debe tener los roles "root" y "hostManager".**

Seleccionamos la base de datos admin:
```mongodb
use admin
```

Creamos el usuario:

```mongodb
db.createUser({
  user:"super",
  pwd: passwordPrompt(),
  roles:[
    {role:"root", db:"admin"},
    {role:"hostManager", db:"admin"}
    ]
})
```

**2. Parad la instancia de MongoDB y volver a iniciarla con el modo de seguridad activo.**

Paramos la instancia: 
```mongodb
db.adminCommand({shutdown:1})
```

Volvemos a iniciarla con el modo de seguridad activo, para ello modificamos el fichero de configuración (mongo.conf) y habilitamos la autenticación:
```
systemLog:
  destination: file
  path: /usr/local/var/log/mongodb/mongo.log
  logAppend: true
storage:
  dbPath: /Users/adrianmorenomonterde/Desktop/AGI/BasesDeDatos
security:
  authorization: enabled
net:
  bindIp: 127.0.0.1, ::1
  ipv6: true
```
**3. Comprobad que lo habéis hecho bien. Para ello, intentad conectaros a la instancia sin autenticaros. En Studio3T y Compass no os debe permitir la conexión y, desde una terminal (mongosh) podréis entrar, pero os debe dar error si intentais ejecutar alguna sentencia (por ejemplo show collections).**

Primero volvemos a cargar el archivo de configuración *mongo.cong*
```
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongod --config /usr/local/etc/mongod.conf
```

En Compass no sale el siguiente error: 
![Error en Compass](./CapturasEjercicio6/captura1.png)

A través de la terminal *mongosh* si que nos deja entrar pero si intentamos ejecutar el comando *show collections* nos sale el siguiente error: 

```console
Last login: Fri Nov 11 13:21:53 on ttys000
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongosh
Current Mongosh Log ID:	636e3fcb9dcbc2add7e93ade
Connecting to:		mongodb://127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&appName=mongosh+1.6.0
Using MongoDB:		6.0.1
Using Mongosh:		1.6.0

For mongosh info see: https://docs.mongodb.com/mongodb-shell/

test> use admin
switched to db admin
admin> show collections
MongoServerError: command listCollections requires authentication
admin> 
```

**4. Desde mongosh del terminal, conectaros a la instancia con autenticación y probad que podéis ejecutar la sentencia del ejercicio anterior.**

Nos conectamos a la instancia con la autenticación:

```console
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongosh --authenticationDatabase "admin" -u "super" -p  

Enter password: *****
Current Mongosh Log ID:	636e6fd9e2fa29d48087df30
Connecting to:		mongodb://<credentials>@127.0.0.1:27017/?directConnection=true&serverSelectionTimeoutMS=2000&authSource=admin&appName=mongosh+1.6.0
Using MongoDB:		6.0.1
Using Mongosh:		1.6.0

For mongosh info see: https://docs.mongodb.com/mongodb-shell/

------
   The server generated these startup warnings when booting
   2022-11-11T16:52:14.802+01:00: Soft rlimits for open file descriptors too low
------

------
   Enable MongoDB's free cloud-based monitoring service, which will then receive and display
   metrics about your deployment (disk utilization, CPU, operation statistics, etc).
   
   The monitoring data will be available on a MongoDB website with a unique URL accessible to you
   and anyone you share the URL with. MongoDB may use this information to make product
   improvements and to suggest MongoDB products and deployment options to you.
   
   To enable free monitoring, run the following command: db.enableFreeMonitoring()
   To permanently disable this reminder, run the following command: db.disableFreeMonitoring()
------

test> use admin
switched to db admin
admin> show collections
system.users
system.version
admin> 
```

**5. En Studio3T y/o Compass, cread una nueva conexión con la autenticación del usuario creado en el ejercicio 1 para poder acceder a todas las bases de datos.**

Hecho, el URI es la siguiente:

```console
mongodb://super:super@localhost:27017/?authMechanism=DEFAULT&authSource=admin
```
**6. Cread un usuario (adminPais) que tenga privilegios de lectura y escritura sobre la base de datos "elPais" y otro usuario (usuarioPais) que sólo tenga permiso de lectura sobre esa base de datos.**

Seleccionamos la base de datos *ElPais*:

```mongodb
use ElPais
```

Creamos el usuario *adminPais*:

```mongodb
db.createUser({
  user:"adminPais",
  pwd:passwordPrompt(),
  roles:[
    {role:"readWrite", db:"ElPais"}
    ]
})
```

Creamos el usuario *usuarioPais*:

```mongodb
db.createUser({
  user:"usuarioPais",
  pwd:passwordPrompt(),
  roles:[
    {role:"read", db:"ElPais"}
    ]
})
```
**7. Desde Studio3T y/o Compass, cread dos nuevas conexiones con la autenticación de los usuarios creados en el ejercicio anterior y probad que, con la conexión del usuario adminPais se puede actualizar el documento pero, que con el usuarioPais no se permite.**

El URI de *adminPais* es el siguiente:

```console
mongodb://adminPais:adminPais@localhost:27017/?authMechanism=DEFAULT&authSource=ElPais
```

Comprobamos que podemos actualizar un documento:

```mongodb
db.noticias.updateOne(
  {etiquetaPrincipal:"Inteligencia artificial"},
  {$set:{titular:"Nuevo Titular"}}
)

{ acknowledged: true,
  insertedId: null,
  matchedCount: 1,
  modifiedCount: 1,
  upsertedCount: 0 }
```

El URI de *usuarioPais* es el siguiente:

```console
mongodb://usuarioPais:usuarioPais@localhost:27017/?authMechanism=DEFAULT&authSource=ElPais
```

Comprobamos que NO podemos actualizar un documento porque al ejecutar lo siguiente:

```mongodb
db.noticias.updateOne(
  {etiquetaPrincipal:"Inteligencia artificial"},
  {$set:{titular:"Nuevo titular"}}
)
```

Mongo nos devuelve esto:

```console
MongoServerError: not authorized on ElPais to execute command { update: "noticias", updates: [ { q: { etiquetaPrincipal: "Inteligencia artificial" }, u: { $set: { titular: "Nuevo titular" } } } ], ordered: true, lsid: { id: UUID("1a7a6ddd-9b33-40e1-91f9-65f366973e48") }, $db: "ElPais" }
```

**8. Con el usuario administrador, cread la base de datos Dieta con las colecciones frutas y personas**

Creamos la base de datos *Dieta*:
```mongodb
use Dieta
```

**Insertad los siguiente documentos en frutas:**
```json
{ "_id" : 1, "nombre" : "manzana", "calorias" : 52 } 
{ "_id" : 2, "nombre" : "plátano", "calorias" : 89 }
{ "_id" : 3, "nombre" : "kiwi", "calorias" : 61 }
{ "_id" : 4, "nombre" : "mango", "calorias" : 60 }
{ "_id" : 5, "nombre" : "ciruela", "calorias" : 46 } 
{ "_id" : 6, "nombre" : "naranja", "calorias" : 47 } 
{ "_id" : 7, "nombre" : "melón", "calorias" : 34 }
```

Hacemos la inserción de los documentos en la colección *frutas*:
```mongodb
db.frutas.insertMany([
  { "_id" : 1, "nombre" : "manzana", "calorias" : 52 }, 
  { "_id" : 2, "nombre" : "plátano", "calorias" : 89 },
  { "_id" : 3, "nombre" : "kiwi", "calorias" : 61 },
  { "_id" : 4, "nombre" : "mango", "calorias" : 60 },
  { "_id" : 5, "nombre" : "ciruela", "calorias" : 46 }, 
  { "_id" : 6, "nombre" : "naranja", "calorias" : 47 } ,
  { "_id" : 7, "nombre" : "melón", "calorias" : 34 }
])
```
**Insertar los siguientes documentos en personas:**
```json
{ "_id" : 1, "nombre" : "Julián", "genero" : "M", "categoria" : "A" } 
{ "_id" : 2, "nombre" : "Esther", "genero" : "F", "categoria" : "A" } 
{ "_id" : 3, "nombre" : "David", "genero" : "M", "categoria" : "B" } 
{ "_id" : 4, "nombre" : "Sofía", "genero" : "F", "categoria" : "B" }
```

Hacemos la inserción de los documentos en la colección *personas*:
```mongodb
db.personas.insertMany([
  { "_id" : 1, "nombre" : "Julián", "genero" : "M", "categoria" : "A" } ,
  { "_id" : 2, "nombre" : "Esther", "genero" : "F", "categoria" : "A" } ,
  { "_id" : 3, "nombre" : "David", "genero" : "M", "categoria" : "B" } ,
  { "_id" : 4, "nombre" : "Sofía", "genero" : "F", "categoria" : "B" }
])
```
**9. Cread un rol que tenga permiso de lectura, inserción, actualización y borrado sobre la colección frutas de la base de datos Dieta, y sólo permiso de lectura sobre la colección personas de la misma base de datos.**

```mongodb
db.createRole({
  role:"rolesDieta",
  privileges:[
    {resource:{db:"Dieta", collection:"frutas"}, actions:["find", "update", "insert", "remove"]},
    {resource:{db:"Dieta", collection:"personas"}, actions:["find"]}
    ],
  roles:[]
})
```
**10. Desde el usuario usuarioPais, intentad acceder a la base de datos de Dieta. Si todo lo anterior está bien, la base de datos no debe aparecer en los entornos Studio3T y Compass entrando con dicho usuario.**

Desde *usuarioPais* no nos aparece en el entorno de Compass la base de datos *Dieta*:

![Captura](./CapturasEjercicio6/captura2.png)

**11. Asignad a usuarioPais el rol del ejercicio anterior y comprobad que puede hacer las operaciones correspondientes, es decir, actualizar, insertar y borrar sobre la colección frutas y sólo consultar sobre la colección personas.**

Asignamos los roles creados en el ejercicio anterior:

```mongodb
db.grantRolesToUser(
  "usuarioPais",
  [{role:"rolesDieta", db:"Dieta"}]
)
```

Comprobamos que ahora podemos actualizar, insertar y borrar sobre la colección frutas:

```mongodb
db.frutas.find()
{ _id: 1, nombre: 'manzana', calorias: 52 }
{ _id: 2, nombre: 'plátano', calorias: 89 }
{ _id: 3, nombre: 'kiwi', calorias: 61 }
{ _id: 4, nombre: 'mango', calorias: 60 }
{ _id: 5, nombre: 'ciruela', calorias: 46 }
{ _id: 6, nombre: 'naranja', calorias: 47 }
{ _id: 7, nombre: 'melón', calorias: 34 }

db.frutas.updateOne(
  {_id:1},
  {$set:{calorias:53}}
)
{ acknowledged: true,
  insertedId: null,
  matchedCount: 1,
  modifiedCount: 1,
  upsertedCount: 0 }

db.frutas.insertOne({_id:8, nombre:"Melocotón", calorias: 69})
{ acknowledged: true, insertedId: 8 }

db.frutas.deleteOne({_id:8})
{ acknowledged: true, deletedCount: 1 }
```

Y también podemos solamente consultar sobre la colección de personas:

```mongodb
db.personas.find()
{ _id: 1, nombre: 'Julián', genero: 'M', categoria: 'A' }
{ _id: 2, nombre: 'Esther', genero: 'F', categoria: 'A' }
{ _id: 3, nombre: 'David', genero: 'M', categoria: 'B' }
{ _id: 4, nombre: 'Sofía', genero: 'F', categoria: 'B' }
```

Porque si intentamos hacer cualquier operación que implique escritura no se nos permite porque no estamos autorizados: 

```mongodb
db.personas.insertOne({_id:5, nombre:"Adrián", genero:"M", categoria:"C"})
```

```console
MongoServerError: not authorized on Dieta to execute command { insert: "personas", documents: [ { _id: 5, nombre: "Adrián", genero: "M", categoria: "C" } ], ordered: true, lsid: { id: UUID("a0f243f3-1def-4ed4-bc35-90a33945cadc") }, $db: "Dieta" }
```
**12. Con el usuario "super", realizad una copia de seguridad de la base de datos Dieta.**

```console
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongodump -u super --authenticationDatabase=admin -d Dieta -o ./copias/Dieta

Enter password for mongo user:

2022-11-14T11:39:52.505+0100	writing Dieta.frutas to copias/Dieta/Dieta/frutas.bson
2022-11-14T11:39:52.507+0100	done dumping Dieta.frutas (7 documents)
2022-11-14T11:39:52.508+0100	writing Dieta.personas to copias/Dieta/Dieta/personas.bson
2022-11-14T11:39:52.508+0100	done dumping Dieta.personas (4 documents)
```

**13. Con el usuario "super", eliminad la base de datos Dieta y restauradla desde la copia de seguridad realizada en el ejercicio anterior.**

Primero eliminamos la base de datos *Dieta*:

```mongodb
db.dropDatabase()
{ ok: 1, dropped: 'Dieta' }
```

Ahora restauramos la copia de seguridad que hemos realizado en el ejercicio 12:

```console
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongorestore -u super --authenticationDatabase=admin ./copias/Dieta
Enter password for mongo user:

2022-11-14T11:47:25.437+0100	preparing collections to restore from
2022-11-14T11:47:25.437+0100	don't know what to do with file "copias/Dieta/.DS_Store", skipping...
2022-11-14T11:47:25.437+0100	reading metadata for Dieta.frutas from copias/Dieta/Dieta/frutas.metadata.json
2022-11-14T11:47:25.438+0100	reading metadata for Dieta.personas from copias/Dieta/Dieta/personas.metadata.json
2022-11-14T11:47:25.528+0100	restoring Dieta.personas from copias/Dieta/Dieta/personas.bson
2022-11-14T11:47:25.559+0100	finished restoring Dieta.personas (4 documents, 0 failures)
2022-11-14T11:47:25.572+0100	restoring Dieta.frutas from copias/Dieta/Dieta/frutas.bson
2022-11-14T11:47:25.584+0100	finished restoring Dieta.frutas (7 documents, 0 failures)
2022-11-14T11:47:25.585+0100	no indexes to restore for collection Dieta.frutas
2022-11-14T11:47:25.585+0100	no indexes to restore for collection Dieta.personas
2022-11-14T11:47:25.585+0100	11 document(s) restored successfully. 0 document(s) failed to restore.
```

**14. Con el usuario "super", restaurad sólo la colección frutas en una nueva colección llamada frutasBackup.**

```console
adrianmorenomonterde@MacBook-Pro-de-Adrian ~ % mongorestore -u super --authenticationDatabase=admin --nsInclude="Dieta.*" --nsFrom="Dieta.frutas" --nsTo="Dieta.frutasBackup" ./copias/Dieta
Enter password for mongo user:

2022-11-14T11:53:24.614+0100	preparing collections to restore from
2022-11-14T11:53:24.614+0100	don't know what to do with file "copias/Dieta/.DS_Store", skipping...
2022-11-14T11:53:24.614+0100	reading metadata for Dieta.frutasBackup from copias/Dieta/Dieta/frutas.metadata.json
2022-11-14T11:53:24.615+0100	reading metadata for Dieta.personas from copias/Dieta/Dieta/personas.metadata.json
2022-11-14T11:53:24.619+0100	restoring to existing collection Dieta.personas without dropping
2022-11-14T11:53:24.619+0100	restoring Dieta.personas from copias/Dieta/Dieta/personas.bson
2022-11-14T11:53:24.641+0100	continuing through error: E11000 duplicate key error collection: Dieta.personas index: _id_ dup key: { _id: 1 }
2022-11-14T11:53:24.641+0100	continuing through error: E11000 duplicate key error collection: Dieta.personas index: _id_ dup key: { _id: 2 }
2022-11-14T11:53:24.641+0100	continuing through error: E11000 duplicate key error collection: Dieta.personas index: _id_ dup key: { _id: 3 }
2022-11-14T11:53:24.641+0100	continuing through error: E11000 duplicate key error collection: Dieta.personas index: _id_ dup key: { _id: 4 }
2022-11-14T11:53:24.641+0100	finished restoring Dieta.personas (0 documents, 4 failures)
2022-11-14T11:53:24.681+0100	restoring Dieta.frutasBackup from copias/Dieta/Dieta/frutas.bson
2022-11-14T11:53:24.693+0100	finished restoring Dieta.frutasBackup (7 documents, 0 failures)
2022-11-14T11:53:24.693+0100	no indexes to restore for collection Dieta.personas
2022-11-14T11:53:24.693+0100	no indexes to restore for collection Dieta.frutasBackup
2022-11-14T11:53:24.693+0100	7 document(s) restored successfully. 4 document(s) failed to restore.
```

![captura3](./CapturasEjercicio6/captura3.png)