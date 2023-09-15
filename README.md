# PC1: Practica Calificada #1
**course:** Programación III  
**unit:** 1 y 2  
**cmake project:** prog3_pc1_teo2_v2023_2
## Indicaciones Específicas
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo fuente (`.cpp`) y un archivo cabecera (`.h`) con el número de la pregunta:
    - `P1.cpp, P1.h`
    - `P2.cpp, P2.h`
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - clases, punteros y sobrecarga de operadores y template de clases (14 points)

El juego de batalla naval (`Battleship`) es un juego clásico en el que cada jugador tiene un tablero en el que coloca varios barcos. Luego, los jugadores se turnan para adivinar las coordenadas de los barcos del oponente y "disparar" en esas coordenadas. Si un disparo golpea un barco, es un "impacto". Si todos los segmentos de un barco son golpeados, el barco es "hundido".

Diseña e implementa la clase de template `board` dentro del namespace `battleship` que permita almacenar de forma generica diferentes tipos `T` (int, char o enum), que permita definirlo de diferentes tamaños, usar un parametro de template **no-tipo** `sz` y adicionalmente debe contar con un parametro **no-tipo** que defina el valor vacio (`empty_value`) de las celdas en el tablero que no tenga nave y del tipo `T`.

La clase debe ser almacenado en memoria dinámica. Implementar los constructores adecuados para inicializar y copiar tableros, así como un destructor para liberar la memoria correctamente.

Para facilitar la impresión del tablero sobrecargar el operador `<<`, asi también implemente las sobrecargas del operador () para acceder y modificar celdas individuales y un metodo `int cells()` que retorne el tamaño del tablero (`sz`) descrito en el primer parrafo.

Proporcionar el método `std::pair<bool, T> shoot(int i, int j)` donde: `i` es la fila y `j` es la columna, este método  permitirá realizar un disparo en la cordenada (`i`, `j`) y retorno true y la nave en caso el disparo impacte y false y una nave nula `empty_value` en caso falle. Considera que si el disparo impacta la celda debe ser actualizada con el valor vacio ('empty_value').

Consejos:
- Recuerde gestionar la memoria de manera eficiente utilizando `new` para la asignación y `delete[]` para la liberación, evitando así potenciales fugas de memoria


**Use Case #1:**
```cpp
  battleship::board<char, 8, '~'> bb;
  cout << bb;
```

**Use Case #2:**
```cpp
  battleship::board<char, 5, '~'> bb = {
      '~', 'D', '~', '~', '~',
      '~', '~', '~', '~', '~',
      '~', '~', 'B', '~', '~',
      '~', '~', '~', '~', 'C',
      '~', '~', '~', '~', '~',
  };
  cout << bb;
  cout << string(13,'-') << endl;
  auto bb2 = bb;
  bb2(4, 0) = 'A';
  cout << bb2;
  cout << string(13,'-') << endl;
  cout << bb;
```

**Use Case #3:**

```cpp
  battleship::board<int, 4> bb;
  battleship::board<int, 4> bb2 {
      0, 0, 3, 0,
      0, 0, 0, 0,
      0, 0, 0, 4,
      1, 0, 0, 0,
  };
  cout << bb;
  cout << string(10, '-') << endl;
  cout << bb2;
  cout << string(10, '-') << endl;
  std::swap(bb, bb2);
  cout << bb;
  cout << string(10, '-') << endl;
  cout << bb2;
  cout << string(10, '-') << endl;
  auto [is_shooted, navy] = bb.shoot(3, 0);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  std::tie(is_shooted, navy) = bb.shoot(3, 3);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  std::tie(is_shooted, navy) = bb.shoot(0, 2);
  cout << boolalpha << is_shooted << " " << navy << endl;
  cout << bb;
  cout << string(10, '-') << endl;
  battleship::board<char, 4, '~'> bb3 {
      '~', '~', '~', '~',
      '~', 'C', 'A', '~',
      '~', '~', '~', '~',
      '~', 'B', '~', '~',
  };
  auto [is_shooted_char, char_navy] = bb3.shoot(3, 1);
  cout << boolalpha << is_shooted_char << " " << char_navy << endl;
  std::tie(is_shooted_char, char_navy) = bb3.shoot(1, 1);
  cout << boolalpha << is_shooted_char << " " << char_navy << endl;
  cout << bb3;
```

**Use Case #4:**

```cpp
  enum navy { sea, torpedo, bomber, submarine };
  battleship::board<navy, 5, navy::sea> bb = {
      sea, bomber, sea,       sea, sea,
      sea, sea,    sea,       sea, sea,
      sea, sea,    submarine, sea, sea,
      sea, sea,    sea,       sea, sea,
      sea, sea,    torpedo  , sea, sea,
  };
  cout << bb;
  cout << string(13,'-') << endl;
  battleship::board<navy, 5, navy::sea> bb2;
  bb2 = bb;
  bb2(4, 0) = bomber;
  for (int i = 0; i < bb2.cells(); ++i) {
    for (int j = 0; j < bb2.cells(); ++j) {
      switch (bb2(i, j)) {
      case sea:
        cout << setw(4) << "~";
        break;
      case torpedo:
        cout << setw(4) << "T";
        break;
      case bomber:
        cout << setw(4) << "B";
        break;
      case submarine:
        cout << setw(4) << "S";
        break;
      }
    }
    cout << endl;
  }
  cout << string(13,'-') << endl;
  cout << bb;
```

## Question #2 - template de función (6 points)
Diseña una función template `find_max_of_min_of_concatenated` que tome un número variable de contenedores y devuelva el valor máximo entre todos los valores mínimos de cada contenedor. 

Además, devolver un contenedor ordenado con todos los valores mínimos de cada contenedor, para retornar ambos valores debe utilizarse `std::pair<T, ContainerResult<T>>` como tipo de retorno, donde ContainerResult es un parametro de template de template. 

La función debe poder recibir contenedores de distintos tipos (por ejemplo, `std::vector`, `std::list`, `std::deque`, etc.).

Restricciones:
- Por defecto, el contenedor ordenado con los valores minimos será de tipo `std::vector`. Sin embargo, debe ser posible especificar un tipo de contenedor diferente.
- Todos los contenedores proporcionados tendrán al menos un elemento.
- Todos los contenedores tendrán el mismo tipo de dato (por ejemplo, todos serán `int`).

**Use Case #1:**
```cpp
  std::vector<int> v1 = {5, 7, 9, 2};
  std::vector<int> v2 = {1, 8, 3, 5};
  std::list<int> l1 = {6, 8, 2, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1, v2, l1);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
```

**Use Case #2:**
```cpp
  std::vector<double> v1 = {5, 7, 9, 3.5};
  std::vector<double> v2 = {1.1, 8, 3, 5};
  std::list<double> l1 = {6.5, 3.0};
  std::list<double> l2 = {1.5};
  std::list<double> l3 = {4, 2.4};
  std::list<double> l4 = {8, 2.1, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1, v2, l1, l2, l3, l4);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
```

**Use Case #3:**
```cpp
  std::vector<double> v1 = {5, 7, 9, 3.5};
  auto [maximum, minimums] = find_max_of_min_of_concatenated(v1);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
```

**Use Case #4:**
```cpp
  std::vector<float> v1 = {1.1f, 8, 3, 5};
  std::list<float> l1 = {1.5f};
  std::deque<float> d1 = {4, 2.4f};
  std::deque<float> d2 = {8, 2.1f, 4};
  auto [maximum, minimums] = find_max_of_min_of_concatenated<std::deque>(v1, l1, d1, d2);
  cout << maximum << endl;
  for (const auto& item: minimums) {
    cout << item << " ";
  }
  cout << endl;
```

