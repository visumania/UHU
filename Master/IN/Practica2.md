# Práctica 2.- Herramientas de Integración (EAI), Identidad Digital

## Pregunta 1
### Introducción
**Facebook** es una red social creada por Mark Zuckerberg mientras estudiaba en la universidad de Harvard. Su objetivo era diseñar un espacio en el que los alumnos de dicha universidad pudieran intercambiar una comunicación fluida y compartir contenido de forma sencilla a través de Internet. 

**Facebook** proporciona una API que permite a los desarrolladores crear aplicaciones que hagan uso de la información alojada en Facebook. Al igual que Twitter, usa el protocolo oauth para realizar la autorización de aplicaciones. 
### Descripción 
Partiendo del ejemplo visto en clase sobre la integración con la red social Twitter, se propone al alumno que modifique dicha aplicación para que permita el acceso tanto a usuarios de Samltest, Twitter y Facebook. Por ahora no es necesario que nuestra aplicación guarde de forma persistente los datos de los usuarios autentificados. Una vez que el usuario acceda a nuestra aplicación, esta mostrará un mensaje de bienvenida para el que se usará el identificador de usuario devuelto por el proveedor de identidad (Samltest, Twitter y Facebook). A continuación mostrará una tabla con los nombres de los atributos devueltos y sus valores. 

Se propone que se sigan los siguientes pasos: 
1. Instale y active el [módulo de Facebook en SimpleSAMLphp](https://github.com/simplesamlphp/simplesamlphp/tree/master/modules/authfacebook).

>docker cp simplesamlphp-module-authtwitter sp:/var/simplesamlphp

>composer require simplesamlphp/simplesamlphp-module-authtwitter

Dentro del archivo config.php en /var/simplesamlphp/config realizamos el siguiente cambio: 
'module.enable' => [
        ...
        'auth.twitter' => true,
    ],


2. Crear una fuente de autentificación nueva en authsources.php para Twitter

Editamos el fichero authsources.php que se encuentra en el directorio /var/simplesamlphp/config:

'twitter' => array(
     'authtwitter:Twitter',
     'key' => 'mi key',
     'secret' => 'mi secret',
     'force_login' => FALSE,
     ‘scope’ => ‘read’
 ),

3. Probar la nueva fuente de autentificación

Modificamos el fichero autsources.php del directorio /var/simplesamlphp/config/authsources.php de la siguiente manera: 



2. En nuestra aplicación web modificamos la fuente de autentificación para usar la creada en el punto 2. 

Configuramos el fichero index.php del directorio /var/www/demo-app de la siguiente manera:

<?php
/**
 * Demo app with SAML auth
 */

/*TODO: Hay que poner la rutas absoluta a las librerías de simplesaml*/
require("/var/simplesamlphp/lib/_autoload.php");


/*TODO: Hay que crear el objeto SimpleSAML que nos permitirá la conexión con
el IDP. Hay que poner la fuente de autorización que vamos a usar, alguna de las
definidas en authsources.php*/
$as = new \SimpleSAML\Auth\Simple("twitter");
if (isset($_GET['signin'])) {
    // TODO: El acceso requiere aututentificación
    $as->requireAuth();

    // Si el usuario está autentificado
    //
    if ($as->isAuthenticated()) {
        // TODO: Obtenemos los atributos
        $saml_attributes = $as->getAttributes();
    }
}
if (isset($_GET['signout'])) {
    // TODO: hago logout
    $as->logout();
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="description" content="">
<meta name="author" content="">
<title>SSO Sign In Demo</title>
<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css" rel="stylesheet">
<link href="styles/css/page.css" rel="stylesheet">
</head>
<body>
<div id="page" class="container">
<?php
if (!isset($saml_attributes)) {
    print "<p><a href=\"?signin\" class=\"btn btn-lg btn-primary\">Sign in</a></p>";
} else {
    /*TODO: MOSTAMOS ALGUNOS DE LOS ATRIBUTOS*/
    print_r($saml_attributes);
    $name = $saml_attributes['twitter.name'][0];
    print "<h3>Welcome {$name}!</h3>";
    print "<p><a href=\"?signout\" class=\"btn btn-lg btn-primary\">Sign out</a></p>";

}
?>
</div>
</body>

Si realizamos estos pasos, la aplicación sólo permitirá el acceso a ususarios de Facebook, ya que hemos quitado la fuente de autentificación de Twitter y/o Samtest de nuestra aplicación. Para permitir que el usuario elija entre una u otra podemos optar entre dos soluciones: 
* Modificar nuestra aplicación web para que le pregunte al usuario la red social a usar y generar la instancia de SimpleSAMLAuth con la fuente de autentificación oportuna.
* Usar el módulo [multiauth de SimpleSAMLphp](https://github.com/simplesamlphp/simplesamlphp/tree/master/modules/multiauth) que permite al usuario elegir qué fuente de autentificación usar. 

Valore las dos soluciones y opte, justificadamente, por aquella que considere mejor.

## Pregunta 2
### Introducción
En un esquema de Identidad Federada las aplicaciones de domestican. Esto es, se les añade la lógica necesaria para actuar como SP ante distintos IdP.

Si la aplicación a domesticar está basada en PHP y nuestra infraestructura de federación usa SAML como estándar para establecer la comunicación entre SP e IdP, podemos usar la [API proporcionada por SimplesamlPHP](https://simplesamlphp.org/docs/stable/simplesamlphp-sp-api.html) tal y como se estudió en clase. 
### Descripción
Partiendo de las integraciones ya hechas (que usan como IdP Samtest, Twitter, Facebook, etc.) y tomando como referencia los ejemplos vistos del uso de la [API proporcionada por SimplesamlPHP](https://simplesamlphp.org/docs/stable/simplesamlphp-sp-api.html) cree una aplicación web que:

Paso 1: Permita elegir al usuario qué IdP, de entre los configurados, quiere usar para loguearse. 

Editamos el fichero config.php que se encuentra en /var/simplesamlphp/config/config.php, poniendo enable.saml20-idp a true: 

'enable.saml20-idp' => true,

Editamos el fichero authsources.php que se encuentra en /var/simplesamlphp/config:

'default-sp' => [
        'saml:SP',

        // The entity ID of this SP.
        'entityID' => 'https://amm.uhu.es/',
        ...
]

Editamos el fichero saml20-idp-hosted.php que se encuentra en el directorio /var/simplesamlphp/metadata: 

$metadata['https://amm.uhu.es/idp'] = [
    /*
     * The hostname of the server (VHOST) that will use this SAML entity.
     *
     * Can be '__DEFAULT__', to use this entry by default.
     */
    'host' => '__DEFAULT__',

    // X.509 key and certificate. Relative to the cert directory.
    'privatekey' => 'server.pem',
    'certificate' => 'server.crt',
    'auth' => 'example-userpass',
]

Generamos la clave pública y privada con ejecutando el siguiente comando:

> cd /var/simplesamlphp/cert

Editamos el fichero authsources.php en el directorio /var/simplesamlphp/config, y comprobamos que lo siguiente esté definido: 

 'example-userpass' => [
        'exampleauth:UserPass',

        'student:studentpass' => [
            'uid' => ['test'],
            'eduPersonAffiliation' => ['member', 'student'],
        ],
        'employee:employeepass' => [
            'uid' => ['employee'],
            'eduPersonAffiliation' => ['member', 'employee'],
        ],
    ],

Comprobamos también que el módulo exampleauth:UserPass está activo

> touch modules/exampleauth/enable

Paso 2: Una vez logueado, la aplicación deberá mostrar un subconjunto de atributos comunes a los distintos IdP. 
Paso 3: La aplicación proporcionará un mecanismo de logout global. 

## Pregunta 3
### Introducción
SimpleSAMLphp es un framework que permite crear tanto SP como IdP. Por defecto, toda la instancia de SimpleSAMLphp está configurada únicamente como SP, pero la activación de su cara SP es bastante sencilla, ya que sólo requiere la activación de la opción oportuna y definir correctamente el fichero de metadatos (tal y cómo se detalló en clase). Uno de los parámetros que debemos establecer en estos metadatos es el **auth** que indica el módulo de autentificación que se usará para autentificar usuarios en el IdP. 
### Descripción
Existen distintos módulos de autentificación soportados por SimpleSAMLphp, uno de ellos (como vimos en clase) es exampleauth. En un entorno real, las fuentes de autentificación más usadas son las bases de datos en sus diferentes sabores (relacional, nosql, en árbol, etc.).

Para esta práctica usaremos como fuente de autentificación un esquema de base de datos albergado en MariaDB. El esquema de base de datos que creemos deberá contener los siguientes campos:
* Nombre del usuario
* Apellidos del usuario
* Edad del usuario
* Correo electrónico
* Identificador único del usuario dentro del scope. 
* Identificador legal único del usuario (DNI, NIE...)
* Nacionalidad
* Teléfono
* Nick de Telegram
* Nick de TikTok
* Nick en Instagram

Los pasos que deberíamos dar son:
1. Despliegue un docker con una instancia de MariaDB

> docker run --detach --name some-mariadb --env MARIADB_USER=user --env MARIADB_PASSWORD=admin --env MARIADB_ROOT_PASSWORD=admin --net in --ip 172.17.97.144 -p 3306:3306  mariadb:latest

2. Cargue el esquema de base de datos indicado

-- Crear la base de datos
CREATE DATABASE usuarios;

-- Usar la base de datos
USE usuarios;

-- Crear la tabla
CREATE TABLE usuario (
  name VARCHAR(50) NOT NULL,
  lastname VARCHAR(100) NOT NULL,
  age INT NOT NULL CHECK (edad > 0),
  email VARCHAR(100) NOT NULL UNIQUE,
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  idCard VARCHAR(20) NOT NULL UNIQUE,
  country VARCHAR(50) NOT NULL,
  telephone VARCHAR(20) NOT NULL UNIQUE,
  nickname_telegram VARCHAR(50) UNIQUE,
  nickname_tiktok VARCHAR(50) UNIQUE,
  nickname_instagram VARCHAR(50) UNIQUE
);

3. En la instancia de SimpleSAMLphp que actúa como IdP instale [módulo sqlauth](https://github.com/simplesamlphp/simplesamlphp-module-sqlauth) y configure una fuente de autentificación que haga uso de este módulo. El IdP deberá usar esta fuente para autentificar a los usuarios. 

Cuando un usuario se autentifica usando un IdP es importante que este le indique los atributos que va a liberar (va a mandar al SP) para que el usuario decida si consiente mandarlos. Para hacer esto deberemos usar el [módulo de consentimiento](https://github.com/simplesamlphp/simplesamlphp-module-consent). Además, no todos los SP necesitan los mismos atributos. 

Nos descargamos los modulos sqlauth y consent desde github, los copiamos en docker (como ya hemos hecho anteriormente con docker cp ...) y ejecutamos los siguientes comandos:

> composer require simplesamlphp/simplesamlphp-module-consent
> composer require simplesamlphp/simplesamlphp-module-sqlauth 

Se pide: 
1. Instale y configure el módulo de consentimiento en el IdP

Editamos el fichero config.php que se encuentra en el directorio /var/simplesamlphp/config:

    'module.enable' => [
        'sqlauth' => true,
        'consent' => true,
    ],

2. Para cada uno de los SP que puedan usar el IdP libere un subconjunto de atributos distinto.

No he podido finalizar la práctica en clase porque el servidor de apache tenía una versión obsoleta y necesitábamos actualizarlo para poder continuar. El problema era que si actualizábamos el servidor de apache se desconfiguraba todo el progreso que habíamos realizado de la práctica, por lo tanto perderíamos todo. 