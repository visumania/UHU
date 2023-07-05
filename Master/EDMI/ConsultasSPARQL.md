# Linked Open Data

## Consultando DBpedia con SPARQL

### Objetivos
- Aprender a extaer información de Wikipedia a través del proyecto DBPedia

Realiza las siguientes consultas mediante el lenguaje *SPARQL* usando alguno de estos editores:
- [Virtuoso](https://dbpedia.org/sparql)
- [Yasgui](https://yasgui.triply.cc/)

###### Realiza las siguientes consultas
**1. Título y Abstract (en inglés) de todas las películas de *Batman***

```sparql
SELECT ?title ?abstract
WHERE {
  ?film a <http://dbpedia.org/ontology/Film> .
  ?film <http://purl.org/dc/terms/subject> <http://dbpedia.org/resource/Category:Batman_films> .
  ?film <http://dbpedia.org/ontology/abstract> ?abstract .
  ?film <http://xmlns.com/foaf/0.1/name> ?title .
  FILTER (LANG(?abstract) = "en" && CONTAINS(?title, "Batman"))
}
```

**2. Título y Abstract (en español) de todas las películas de *Batman***

```sparql
SELECT ?title ?abstract
WHERE {
  ?film a <http://dbpedia.org/ontology/Film> .
  ?film <http://purl.org/dc/terms/subject> <http://dbpedia.org/resource/Category:Batman_films> .
  ?film <http://dbpedia.org/ontology/abstract> ?abstract .
  ?film <http://xmlns.com/foaf/0.1/name> ?title .
  FILTER (LANG(?abstract) = "es" && CONTAINS(?title, "Batman"))
}
```

**3. Nombre de películas y nombre del director de películas de 1970, ordenados alfabéticamente por el nombre de la película**

```sparql
SELECT DISTINCT ?title ?nombreDirector
WHERE {
  ?film rdf:type dbo:Film .
  ?film rdfs:label ?title .
  ?film dbo:director ?nombreDirector .
  FILTER(LANG(?title) = "en")
}
ORDER BY ?title
```

**4. Nombre de todos los actores que aparecen en las películas *"Resident Evil"*, ordenados alfabéticamente**

```sparql
SELECT DISTINCT ?nombreActor
WHERE {
  ?film dbo:starring ?actor .
  ?film foaf:name ?filmName .
  ?actor foaf:name ?nombreActor .
  FILTER(CONTAINS(LCASE(?filmName), "resident evil"))
}
ORDER BY ?nombreActor
```

**5. Nombre de películas de la década de los 90 en la que intervienen actores de la década de los 70. Para comprobar que la consulta es correcta, mostrar también el nombre de los actores, su fecha de nacimiento y fecha de la película**

```sparql
SELECT ?film ?actores 
WHERE {
  ?film rdf:type dbo:Film .
  ?film dct:subject dbc:1990s_English-language_films .
  ?film dbp:starring ?actores . 
  ?actores dbo:birthDate ?fechaNacimiento . 
  FILTER (?fechaNacimiento >= xsd:dateTime("1970-01-01") && 
          ?fechaNacimiento <= xsd:dateTime("1979-12-31"))
}
```

*Nota:* La fecha de las películas no se ha podido encontrar ya que no he encontrado ningún campo que te devuelva exactamente la fecha de una película. No obstante, algunas llevan en el nombre el año en el que se estrenó dicha película. 

**6. Obtener el listado de superpoderes y nombres de todos los superhéroes de los comics de *Marvel***
`Categoría: Marvel_Comics_American_superheroes`

```sparql
SELECT ?nombre ?poderes
WHERE {
  ?nombreSuperheroe dct:subject dbc:Marvel_Comics_American_superheroes . 
  ?nombreSuperheroe foaf:givenName ?nombre . 
  ?nombreSuperheroe dbp:powers ?poderes . 
}
ORDER BY ?nombre
```

**7. Obtener el nombre de los jugadores que han jugado en la selección de España y en el Real Betis**

```sparql
SELECT DISTINCT ?nombreJ
WHERE {
  ?nombreJugador dbp:nationalteam dbr:Spain_national_football_team . 
  ?nombreJugador dbo:team dbr:Real_Betis .
  ?nombreJugador foaf:name ?nombreJ .
  FILTER(LANG(?nombreJ) = "en")
}
```

**8. Obtener los grupos de *Heavy Metal* de la década de los 80 y 90, incluyendo su país de origen**
`Categoría: Heavy_metal_music`

```sparql
SELECT ?grupoNombre ?inicio ?origen
WHERE {
      ?grupo rdf:type dbo:Band .
      ?grupo dbo:genre dbr:Heavy_metal_music .
      ?grupo rdfs:label ?grupoNombre .
      ?grupo dbo:activeYearsStartYear ?inicio . 
      ?grupo dbp:origin ?origenB .
      ?origen rdfs:label ?origenB .
      FILTER(year(?inicio) >= 1980 && year(?inicio) < 2000) . 
      FILTER (lang(?grupoNombre) = "es")
}
ORDER BY (year(?inicio))
```