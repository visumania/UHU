# Ejercicio P3. PostGIS. Relaciones espaciales

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