# Ft-Maincore

Repositorio con proyectos del cursus de 42 Málaga realizados por [@marioga2](https://github.com/Mariogarluu).

## 📑 Índice

- [Sobre este repositorio](#sobre-este-repositorio)
- [Proyectos](#proyectos)
  - [1. Libft](#1-libft)
  - [2. ft_printf](#2-ft_printf)
  - [3. get_next_line](#3-get_next_line)
  - [4. Born2beRoot](#4-born2beroot)
  - [5. push-swap](#5-push-swap)
  - [6. minitalk](#6-minitalk)
  - [7. so_long](#7-so_long)
  - [8. Exam 02](#8-exam-02)
- [Compilación](#compilación)
- [Autor](#autor)

---

## Sobre este repositorio

Este repositorio contiene todos los proyectos desarrollados durante el cursus común de 42 Málaga. Cada proyecto está organizado en su propia carpeta con su código fuente, Makefile y archivos necesarios.

---

## Proyectos

### 1. Libft

**Descripción:** Librería de funciones básicas de C que reimplementa funciones estándar de la biblioteca de C y añade funciones adicionales útiles.

**Directorio:** `libft/`

**Funciones incluidas:**
- Funciones de caracteres: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, etc.
- Funciones de string: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_split`, etc.
- Funciones de memoria: `ft_memset`, `ft_memcpy`, `ft_memmove`, etc.
- Funciones de conversión: `ft_atoi`, `ft_itoa`
- Funciones de output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`
- Funciones bonus de listas enlazadas

**Compilación:**
```bash
cd libft
make        # Compila la librería libft.a
make bonus  # Compila con funciones bonus
make clean  # Limpia archivos objeto
make fclean # Limpia todo
make re     # Recompila
```

---

### 2. ft_printf

**Descripción:** Reimplementación de la función printf de C con soporte para múltiples conversores.

**Directorio:** `ft_printf/`

**Conversores implementados:**
- `%c` - Carácter
- `%s` - String
- `%p` - Puntero en hexadecimal
- `%d` / `%i` - Entero decimal
- `%u` - Entero sin signo
- `%x` / `%X` - Hexadecimal (minúsculas/mayúsculas)
- `%%` - Signo de porcentaje

**Compilación:**
```bash
cd ft_printf
make        # Compila la librería libftprintf.a
make clean  # Limpia archivos objeto
make fclean # Limpia todo
make re     # Recompila
```

---

### 3. get_next_line

**Descripción:** Función que lee una línea de un file descriptor, útil para leer archivos línea por línea.

**Directorio:** `get_next_line/`

**Características:**
- Lee de cualquier file descriptor
- Buffer size configurable
- Gestión eficiente de memoria
- Funciona con múltiples file descriptors

**Uso:**
```c
#include "get_next_line.h"

char *line;
int fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

### 4. Born2beRoot

**Descripción:** Proyecto de administración de sistemas que implica la configuración de una máquina virtual con Debian.

**Directorio:** `Born2beRoot/`

**Contenido:**
- `monitoring.sh` - Script de monitorización del sistema
- `signature.txt` - Firma de la máquina virtual

**Conceptos cubiertos:**
- Virtualización
- Particionado LVM
- Configuración SSH
- Firewall (UFW)
- Políticas de contraseñas
- Sudo configuración
- Cron jobs

---

### 5. push-swap

**Descripción:** Algoritmo de ordenación usando dos pilas con un conjunto limitado de instrucciones.

**Directorio:** `push-swap/`

**Operaciones disponibles:**
- `sa`, `sb`, `ss` - Swap
- `pa`, `pb` - Push
- `ra`, `rb`, `rr` - Rotate
- `rra`, `rrb`, `rrr` - Reverse rotate

**Compilación:**
```bash
cd push-swap
make        # Compila el ejecutable push_swap
make clean  # Limpia archivos objeto
make fclean # Limpia todo
make re     # Recompila
```

**Uso:**
```bash
./push_swap 4 67 3 87 23
```

**Testing:**
```bash
# Comprobar con el checker (incluido)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

---

### 6. minitalk

**Descripción:** Programa de comunicación entre cliente y servidor usando señales UNIX.

**Directorio:** `minitalk/`

**Componentes:**
- `server` - Servidor que recibe mensajes
- `client` - Cliente que envía mensajes
- Comunicación mediante señales `SIGUSR1` y `SIGUSR2`

**Compilación:**
```bash
cd minitalk
make        # Compila server y client
make clean  # Limpia archivos objeto
make fclean # Limpia todo
make re     # Recompila
```

**Uso:**
```bash
# Terminal 1: Iniciar servidor
./server

# Terminal 2: Enviar mensaje (usar PID mostrado por server)
./client [PID] "Hola Mundo"
```

---

### 7. so_long

**Descripción:** Juego 2D simple usando la librería gráfica MiniLibX.

**Directorio:** `so_long/`

**Características:**
- Juego de laberinto con vista top-down
- Recolección de objetos
- Movimiento del jugador con WASD o flechas
- Validación de mapas
- Contador de movimientos

**Compilación:**
```bash
cd so_long
make        # Compila el ejecutable so_long
make clean  # Limpia archivos objeto
make fclean # Limpia todo
make re     # Recompila
```

**Uso:**
```bash
./so_long maps/map.ber
```

**Formato del mapa:**
- `1` - Muro
- `0` - Espacio vacío
- `C` - Coleccionable
- `E` - Salida
- `P` - Posición inicial del jugador

---

### 8. Exam 02

**Descripción:** Soluciones de ejercicios del examen 02 de 42.

**Directorio:** `exam 02/`

**Estructura:**
- `level0/` - Ejercicios nivel 0
- `level1/` - Ejercicios nivel 1 (ejemplo: `max.c`)
- `level2/` - Ejercicios nivel 2 (ejemplo: `paramsum.c`, `tab_mult.c`)
- `level3/` - Ejercicios nivel 3

**Ejercicios incluidos:**
- **paramsum.c** - Cuenta el número de parámetros
- **tab_mult.c** - Imprime tabla de multiplicar
- **max.c** - Encuentra el máximo en un array
- Y más...

---

## Compilación

Cada proyecto incluye su propio Makefile con las siguientes reglas comunes:

```bash
make        # Compila el proyecto
make clean  # Elimina archivos objeto (.o)
make fclean # Elimina archivos objeto y ejecutables/librerías
make re     # Recompila todo desde cero
```

Algunos proyectos también incluyen:
```bash
make bonus  # Compila funciones bonus (libft)
make norm   # Ejecuta norminette (minitalk)
```

---

## Autor

**Mario García**
- GitHub: [@Mariogarluu](https://github.com/Mariogarluu)
- 42 Intra: marioga2
- Escuela: 42 Málaga

---

*Este repositorio es con fines educativos. Si eres estudiante de 42, te animo a que intentes resolver los proyectos por ti mismo antes de consultar estas soluciones.*
