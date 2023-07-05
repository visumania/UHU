# Examen bases de datos espaciales 

## Ejercicio P2. PostGIS. Consultas con geometrías

##### Escribir las sentencias *SELECT* para las siguientes consultas:

**1. ¿Cuál es el área de trabajo del barrio *West Village*?**

```sql
SELECT ST_Area(geom) 
FROM nyc_neighborhoods
WHERE name='West Village';
```

**2. ¿Cuál es el área del distrito *Manhattan*?**

```sql
SELECT SUM(ST_Area(geom)) 
FROM nyc_neighborhoods
WHERE boroname='Manhattan';
```

**3. ¿Cuál es la longitud de la calle *Columbus Cir*?**

```sql
SELECT ST_Length(geom)
FROM nyc_streets
WHERE name='Columbus Cir';
```

**4. ¿Cuál es la longitud total (en kilómetros) de las calles de Nueva York?**

```sql
SELECT SUM(ST_Length(geom))/1000
FROM nyc_streets;
```

**5. ¿Cuál es la representación *JSON* de los límites del barrio *West Village*?**

```sql
SELECT ST_AsGeoJSON(geom)
FROM nyc_neighborhoods
WHERE name='West Village';
```

**6. ¿Cuál es la longitud de las calles de Nueva York, agrupalas por su tipo y con ordenación descendente por la longitud?**

```sql
SELECT type, SUM(ST_Length(geom)) AS x
FROM nyc_streets
GROUP BY type 
ORDER BY x desc;
```

## Ejercicio P3. PostGIS. Relaciones espaciales

###### Resolver las siguientes consultas

**1. ¿En qué barrio y distrito está la calle *Atlantic Commons*?**

```sql
SELECT name, boroname
FROM nyc_neighborhoods
WHERE ST_INTERSECTS(geom, 
                (SELECT geom
                FROM nyc_streets
                WHERE name = 'Atlantic Commons'));
```

**2. ¿Con qué calles se cruza la calle *Atlantic Commons*?**

```sql
SELECT name 
FROM nyc_streets
WHERE ST_Touches(geom,
                (SELECT geom
                FROM nyc_streets
                WHERE name = 'Atlantic Commons'))
```

**3. ¿Cuánta gente vive aproximadamente a 50 metros de la calle *Davidson St*?**

```sql
SELECT SUM(popn_total)
FROM nyc_census_blocks
WHERE ST_DWithin(geom,
            (SELECT geom
            FROM nyc_streets
            WHERE name = 'Davidson St'), 50)
```

**4. ¿Qué calles están a unos 10 metros de la estación *Broad St*?**

```sql
SELECT name
FROM nyc_streets
WHERE ST_DWithin(geom,
                (SELECT geom
                FROM nyc_subway_stations
                WHERE name = 'Broad St'), 10)
```

## Espaciales PostGIS 3

### Punto (point)
- `ST_X(geometría)`: devuelve la coordenada X.
- `ST_Y(geometría)`: devuelve la coordenada Y.

### Cadena de líneas (linestring)
- `ST_Length(geometría)`: devuelve la longitud de la cadena de líneas.
- `ST_StartPoint(geometría)`: devuelve la primera coordenada como un punto.
- `ST_EndPoint(geometría)`: devuelve la última coordenada como un punto. 
- `ST_NPoints(geometría)`: devuelve el número de coordenadas de la cadena de líneas. 

### Polígono (polygon)
- `ST_Area(geometría)`: devuelve el área.
- `ST_NRings(geometría)`: devuelve el número de anillos (generalmente 1, si no hay huecos).
- `ST_ExteriorRing(geometría)`: devuelve el anillo exterior como una cadena de línea.
- `ST_InteriorRingN(geometría,n)`: devuelve un anillo interior específico como una cadena de línea. 
- `ST_Perimeter(geometría)`: devuelve la longitud de todos los anillos.

### Colección (collection)
#### Tipos: 
1. `MultiPoint` es una colección de puntos.
2. `MultiLineString` es una colección de cadenas de líneas.
3. `MultiPolygon` es una colección de polígonos. 
4. `GeometryCollection` es una colección heterogénea de cualquier geometría (incluidas otras colecciones).


- `ST_NumGeometries(geometría)`: devuelve el número de partes en la colección.
- `ST_GeometryN(geometría,n)`: devuelve la parte especificada. 
- `ST_Area(geometría)`: devuelve el área total.
- `ST_Length(geometría)`: devuelve la longitud total. 

### Geometrías
- *`spatial_ref_sys`*, que define los sistemas de referencia espacial conocidos por la base de datos. 
- *`geometry_columns`*, que proporciona la relación de objetos con atributos geométricos y sus detalles. 

### Conversión entre formatos
- *WKT (Well-Known Text)*
  - `ST_GeomFromText(text,srid)`: devuelve geometría.
  - `ST_AsText(geometría)`: devuelve texto.
  - `ST_AsEWKT(geometría)`: devuelve texto.
- *WKB (Well-Known Binary)*
  - `ST_GeomFromWKB(bytea)`: devuelve geometría.
  - `ST_AsBinarySVG(geometría)`: devuelve bytea. 
  - `ST_AsEWKB(geometría)`: devuelve bytea.
- *GML (Geographic Mark-up Language)*
  - `ST_GeomFromGML(texto)`: devuelve geometría.
  - `ST_AsGML(geometría)`: devuelve texto. 
- *KML (Keyhole Mark-up Language)*
  - `ST_GeomFromKML(texto)`: devuelve geometría.
  - `ST_AsKML(geometría)`: devuelve texto.
- *GeoJSON*
  - `ST_AsGeoJSON(geometría)`: devuelve texto
- *SVG (Scalable Vector Graphics)*
  - `ST_AsSVG(geometría)`: devuelve texto. 

### Funciones que aparece en la lista de funciones pero no aparece en las diapositivas:
- `ST_SRID`
- `ST_GeometryType`
- `ST_NDims`

## Espaciales PostGIS 4

### Relaciones espaciales
- `ST_Equals(geometría A, geometría B)`: comprueba la igualdad espacial de dos geometrías. Devuelve `Verdadero` si dos geometrías representan la misma estructura geométrica y son coincidentes.
- `ST_Intersects(geometría A, geometría B)`: devuelve `Verdadero` si las dos formas tienen algún espacio en común, es decir, si sus límites o interiores se intersecan. 
- `ST_Disjoint(geometría A, geometría B)`: es el opuesto al anterior. Suele ser más eficiente probar "NOT Intersects..." que probar este, porque las pruebas de intersección pueden indexarse espacialmente. 
- `ST_Crosses(geometría A, geometría B)`: devuelve `Verdadero` si la intersección da como resultado una geometría cuya dimensión es una menos que la máxima dimensión de las dos geometrías, y la intersección es interior a ambas geometrías. Se aplica en comparaciones:
  - multipunto/polígono
  - multipunto/cadena de líneas
  - cadena de líneas/cadena de líneas
  - cadena de líneas/polígono
  - cadena de líneas/multipolígono
- `ST_Overlaps(geometría A, geometría B)`: compara dos geometrías de la misma dimensión y devuelve `Verdadero` si su intersección da como resultado una geometría diferente de ambas pero de la misma dimensión.
- `ST_Touches(geometría A, geometría B)`: comprueba si dos geometrías se tocan en sus límites, pero no se intersecan en sus interiores. Es decir, devuelve `Verdadero` si cualquiera de los límites de las geometrías se intersecan o si solo uno de los interiores de una geometría se interseca con el límite de la otra.
- `ST_Within(geometría A, geometría B)`: devuelve `Verdadero` si la primera geometría está completamente dentro de la segunda geometría.
- `ST_Contains(geometría A, geometría B)`: devuelve `Verdadero` si la segunda geometría está completamente contenida por la primera geometría. 
- `ST_Distance(geometría A, geometría B)`: devuelve la distancia más corta entre dos geometrías.
- `ST_DWithin`: comprueba si dos objetos están a una determinada distancia. 