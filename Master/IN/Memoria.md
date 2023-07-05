# Integración de Información Corporativa

## Práctica V. Bloque II. Creación y Manipulación de cubos OLAP con la herramienta: *OlapCube*

### 1. Análisis del problema a resolver

Se pretende realizar un análisis basado en Inteligencia de Negocios sobre la Base de Datos de un almacén de verduras. 

Teniendo en cuenta la naturaleza de la base de datos, se desea determinar qué aspectos afectan a las ventas del almacén, así como la forma en que afectan, para poder tomar decisiones en base a esta información. 

En concreto el responsable del almacén de verduras, tiene especial interés en que se analice y de respuesta de los siguientes aspectos: 

**A1** ¿Afecta la belleza de los vendedores en sus ventas?

<u>Dimensiones</u>
- `Vendedores.Guap@`
  
<u>Medidas</u>
- `Ventas.Kilos (Sum of Kilos)` 

![Pregunta_1](../P5/Cubo1/Pregunta1.jpg)

Si observamos el gráfico podemos afirmar que la belleza de los vendedores **SI** afecta en sus ventas porque los vendedores/as guapos/as venden muchísimos más kilogramos que los que no son guapos/as. 

**A2** ¿Influye en las ventas del almacén el estado civil de los vendedores?

<u>Dimensiones</u>
- `Vendedores.EstalCivil`
  
<u>Medidas</u>
- `Ventas.Kilos (Sum of Kilos)`

![Pregunta_2](../P5/Cubo2/Pregunta2.jpg)

Si observamos el gráfico generado podemos apreciar que los *arrejuntados*, *divorciados* y *separados* son los que más cantidad venden. Sin embargo, los *solteros* y los *viudos* son los que menos cantidad venden. 

**A3** ¿Cuál es la categoría de productos más vendida anualmente?

<u>Dimensiones</u>
- `Grupos.NombreGrupo`
- `Ventas.Fecha` --> Agrupando por *year* (anualmente)
  
<u>Medidas</u>
- `Ventas.Kilos` (Sum of Kilos)

![Pregunta_3_1998](../P5/Cubo3/Pregunta3_1998.jpg)

En 1998 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_1999](../P5/Cubo3/Pregunta3_1999.jpg)

En 1999 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_2000](../P5/Cubo3/Pregunta3_2000.jpg)

En 2000 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_2001](../P5/Cubo3/Pregunta3_2001.jpg)

En 2001 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_2002](../P5/Cubo3/Pregunta3_2002.jpg)

En 2002 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_2003](../P5/Cubo3/Pregunta3_2003.jpg)

En 2003 la categoría de productos más vendida fueron las frutas. 

![Pregunta_3_2004](../P5/Cubo3/Pregunta3_2004.jpg)

En 2004 la categoría de productos más vendida fueron las frutas, aunque no hay registro de ninguna otra categoría. 

Una vez se ha analizado el gráfico generado en cada año podemos decir en todos los años la categoría más vendida ha sido la fruta. 

**A4** ¿Cuál es la categoría de productos más vendida en Madrid?

<u>Dimensiones</u>
- `Grupos.NombreGrupo`
- `Vendedores.Poblacion`

<u>Medidas</u>
- `Ventas.Kilos` (Sum of Kilos)

![Pregunta_4](../P5/Cubo4/Pregunta4.jpg)

Observando el gráfico podemos afirmar que la categoría más vendida en Madrid históricamente han sido las frutas. 

**A5** ¿Qué producto de la categoría *"Frutas"* es el más vendido anualmente?

<u>Dimensiones</u>
- `Productos.NomProducto`
- `Ventas.Fecha` --> Agrupando por *year* (anualmente)

<u>Medidas</u>
- `Ventas.Kilos` (Sum of Kilos)

Los gráficos que están a continuación se han generado con todos los productos de todas las categorían por lo tanto hay que tener en cuenta que las frutas son: 
- Mandarinas
- Melones
- Plátanos
- Uvas
- Naranjas
- Melocotón
- Manzana

![Pregunta_5_1998](../P5/Cubo5/1998.png)

En 1998 la fruta más vendida fué la manzana. 

![Pregunta_5_1999](../P5/Cubo5/1999.png)

En 1999 la fruta más vendida fué el melón.

![Pregunta_5_2000](../P5/Cubo5/2000.png)

En 2000 la fruta más vendida fué el melón.

![Pregunta_5_2001](../P5/Cubo5/2001.png)

En 2001 la fruta más vendida fué melocotón.

![Pregunta_5_2002](../P5/Cubo5/2002.png)

En 2002 la fruta más vendida fué el platano. 

![Pregunta_5_2003](../P5/Cubo5/2003.png)

En 2003 la fruta más vendida fué el melón. 

![Pregunta_5_2004](../P5/Cubo5/2004.png)

En 2004 la fruta más vendida fué el melón, aunque también fué la única fruta que se vendió. 

En los 7 años analizados en los gráficos anteriores, en 4 años la fruta más vendida fué el melón, por lo que podemos afirmar que el melón es, históricamente, la fruta más vendida de nuestro almacén. 

**A6** ¿Qué vendedor ha vendido más hortalizas? ¿Qué cantidad ha vendido?

<u>Dimensiones</u>
- `Vendedores.NombreVendedor`
- `Grupos.NombreGrupo`

<u>Medidas</u>
- `Ventas.Kilos` (Sum of Kilos)

![Pregunta_6](../P5/Cubo6/Pregunta6.png)

Observando el gráfico anterior podemos afirmar que Ramón ha sido el vendedor que más hortalizas ha vendido.

*Nota:* Cuando generé el gráfico (ordenador Windows) no apunté el número exacto para responder a la pregunta de qué cantidad ha vendido, y ahora que estoy redactando la memoria en mi ordenador (MacOS) no puedo consultarla de nuevo al no poder usar el programa. No obstante en el gráfico se puede apreciar que Ramón ha vendido un poco más de 167.500 kilogramos de hortalizas. 

**A7** ¿En qué población se vende más cantidad anualmente?

<u>Dimensiones</u>
- `Vendedores.Poblacion`
- `Ventas.Fecha` --> Agrupando por *year* (anualmente)

<u>Medidas</u>
- `Ventask.Kilos` (Sum of Kilos)

![Pregunta_7_1998](../P5/Cubo7/1998.png)

En 1998 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_1999](../P5/Cubo7/1999.png)

En 1999 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_2000](../P5/Cubo7/2000.png)

En 2000 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_2001](../P5/Cubo7/2001.png)

En 2001 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_2002](../P5/Cubo7/2002.png)

En 2002 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_2003](../P5/Cubo7/2003.png)

En 2003 se vendió más cantidad en *Sant Esteve sesrovires*

![Pregunta_7_2004](../P5/Cubo7/2004.png)

En 2004 se vendió más cantidad en *Madrid*, aunque también es la única población de la que se tiene registros en ese año. 

Una vez analizados los gráficos de todos los años podemos afirmar que, históricamente, la población en donde más cantidad de productos se han vendido ha sido *Sant Esteve sesrovires*. 