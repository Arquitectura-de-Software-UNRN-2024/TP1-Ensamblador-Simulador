## TP1: Ensamblador y Simulador 
UNRN - ING. ELECTRÓNICA

**Autores:**
* Pojmaevich Mirko (mirkopoj@gmail.com) 
* Torletti Lara (lara.a.torletti@gmail.com)

**Materia:**
Arquitectura de Sotware B5647

**Profesor:**
Martín Morixe

**Objetivo de proyecto**

Diseñar e implementar dos programas en C++: un ensamblador y un simulador de procesador.

* Ensamblador:
  - Entrada: Un archivo de texto que contiene código en lenguaje ensamblador
  - Salida: Un archivo binario que contiene instrucciones de código máquina en formato ejecutable
    
| Instrucción | Código | Ejemplo en Ensamblador | Ejemplo en Código | Ejecución |
|---|---|---|---|---|
| LOAD | 1 | LOAD 7 | 0x01.00.00.07 | ACC = 7 |
| ADD | 2 | ADD 2 | 0x02.00.00.02 | ACC += 2 |
| PRINT | 3 | PRINT | 0x03.00.00.00 | Imprime ACC |

* Simulador de Procesador:
  - Entrada: Un archivo binario que contiene instrucciones de código máquina en formato ejecutable
  - Modos de funcionamiento:
    - Modo depuración: Muestra paso a paso cada instrucción ejecutada
    - Modo normal: Ejecuta el programa sin acciones especiales
    - Arquitectura del Procesador: 32 bits, big endian

> [!CAUTION]
> Este proyecto está realizado con C++20, por ende utilice un compilador C++ compatible.

> [!WARNING]
> Correr los test depende de Criterion. [Ver más sobre criterion](https://criterion.readthedocs.io/en/master/intro.html)

**Instrucciones de uso**
* Utilice un compilador C++ compatible con C++20.
* Haga:
 ```{bash}
git clone https://github.com/Arquitectura-de-Software-UNRN-2024/TP1-Ensamblador-Simulador.git
make
```
* Los ejecutables luego de hacer make, se encontrarán en bin/.
* para correr el ensamblador:
 ```{bash}
#En el caso de querer correr el ensamblador
bin/ensamblador "nombre_arhivo_in".txt -o "nombre_archivo_out".bin
# -h v --help es una flag opcional para recibir ayuda sobre como utilizar el ensamblador
# -o es una flag opcional y si no se aclara camino de salida elije out-"nombre_archivo".bin
```
* para correr el simulador:
 ```{bash}
#En el caso de querer correr el simulador
bin/simulador "nombre_arhivo_in".bin 
# -h v --help es una flag opcional para recibir ayuda sobre como utilizar el simulador
# por defecto el simulador es de modo normal, para acceder al modo debug se debe poner la flag -d v --debug
```
