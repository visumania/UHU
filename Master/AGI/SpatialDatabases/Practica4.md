# Ejercicio 4. PostGIS. Vistas y capas

###### Resolver los siguientes ejercicios:

**1. Crear en *PostgreSQL* una vista para seleccionar el distrito de *Manhattan.***
```sql
CREATE VIEW bManhattan
AS
SELECT *
FROM nyc_neighborhoods
WHERE boroname = 'Manhattan';
```
**2. En *QGIS*, carga la capa de los barrios de NYC y también la correspondiente a la vista de *Manhattan* creada en el ejercicio anterior.**
![Imagen1](CapturasPractica4/Captura1.png)
**3. Crea en *PostgreSQL* una vista para seleccionar los bloques (*census_blocks*) con más de 300 habitantes *Asian*.**
```sql
CREATE VIEW asianPop
AS
SELECT *
FROM nyc_census_blocks
WHERE popn_asian>300;
```
**4. En *QGIS*, carga la capa de los barrios de NYC y también la correspondiente a la vista creada en el ejercicio anterior.**
![Imagen2](CapturasPractica4/Captura2.png)