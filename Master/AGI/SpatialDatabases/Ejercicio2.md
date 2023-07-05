# Ejercicio P2. PostGIS. Consultas con geometrías

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