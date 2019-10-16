# Ejercicios prácticos

<ul>
<li>Suponga que usted es un programador de videojuegos, desarrolle una aplicación sencilla para verificar la utilidad del concepto de polimorfismo. Su aplicación tendrá 3 personajes que son luchadores en un videojuego:
<ol>
<li>Codifique una interfaz "compTecnicaEspecial" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "tecnicaEspecial"</li>
<li>Codifique una interfaz"compGolpePatada" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "patada"</li>
<li>Codifique una interfaz "compPoder" que tiene un constructor por defecto, un destructor y un método virtual puro llamado "poder"</li>
<li>Diseñe 3 clases que heredan de la interfaz "compTecnicaEspecial", cada una implementa el método "tecnicaEspecial" de distinta forma de acuerdo al personaje que va a utilizar dicha técnica. Por ejemplo: El personaje Goku ejecuta como técnica especial la Genkidama, el personaje Naruto ejecuta la técnica Rasengan, etc. Estas clases cuentan con constructor por defecto y destructor.</li>
<li>Diseñe 3 clase que heredan de la interfaz "compGolpePatada", cada una implementa el método "patada" de acuerdo al personaje. Estas clases cuentan con constructor por defecto y destructor.</li>
<li>Diseñe 3 clase que heredan de la interfaz "compPoder", cada una implementa el método "poder" de acuerdo al personaje. Por ejemplo Goku hace un kame-hame-ha, Ryu lanza un ado-ken, etc. Estas clases cuentan con constructor por defecto y destructor.</li>
<li>Desarrolle una clase "Luchador" que tiene los siguientes miembros: un puntero "compTecnicaEspecial" a objetos de la clase "CompTecnicaEspecial", un puntero "compGolpePatada" a objetos de la clase "CompGolpePatada", un puntero "compPoder" a objetos de la clase "CompPoder", un método redefinible "saludo" que no recibe parámetros ni retorna valor alguno, un método "ejecutarEspecial" que invoca un método "tecnicaEspecial" del puntero compTecnicaEspecial, un método "ejecutarPatada" que invoca el método "patada" a través del puntero compGolpePatada, un método "ejecutarPoder" que invoca un método "poder" a través del puntero compPoder. Esta clase tiene un constructor por defecto y un destructor.</li>
<li>Desarrolle 3 clases que hereden de la clase "Luchador", estas clases corresponden a los personajes del videojuego (Goku, Naruto, Iron-Man, etc.) Estas clases redefinen el método "saludo" de la clase Luchador para que cada personaje haga su saludo característico. Estas clases cuentan también con un constructor por defecto en el que los punteros heredados de la clase Luchador se apuntan (reservan memoria) con el operador `new` a objetos de las clases creadas en los numerales 4, 5 y 6 dependiendo del personaje que está implementando. Las clases cuentan también con destructor para liberar con el operador <b>delete</b> la memoria reservada para los punteros.</li>
<li>Codifique una pequeña aplicación en la que se creen 3 personajes para el videojuego usando polimorfismo, es decir con punteros del tipo de la clase Luchador reserve memoria (con el operador <b>new</b>) para objetos de las clases que desarrolló en el numeral anterior. Con cada uno de los punteros ejecute los métodos saludo, ejecutarEspecial, ejecutarPatada y ejecutarPoder. No olvide liberar la memoria con el operador <b>delete</b>.
</ol>
</li>
</ul>
