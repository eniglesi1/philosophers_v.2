# Philosophers

Proyecto de concurrencia de 42 basado en el problema de los filosofos.
El objetivo es simular varios filosofos que comen, duermen y piensan usando
threads y mutexes, evitando condiciones de carrera y deadlocks.

```sh
cd philo
make
```

## Uso esperado

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: numero de filosofos y tenedores.
- `time_to_die`: tiempo maximo sin comer antes de morir.
- `time_to_eat`: tiempo que tarda un filosofo en comer.
- `time_to_sleep`: tiempo que tarda en dormir.
- `number_of_times_each_philosopher_must_eat`: opcional; si todos comen esa cantidad, termina la simulacion.

## Funciones permitidas

- `memset`: rellenar memoria con un valor, util para inicializar structs.
- `printf`: imprimir mensajes por pantalla.
- `malloc`: reservar memoria dinamica.
- `free`: liberar memoria reservada con `malloc`.
- `write`: escribir en un file descriptor; alternativa mas directa a `printf`.
- `usleep`: pausar la ejecucion durante microsegundos.
- `gettimeofday`: obtener el tiempo actual; sirve para calcular timestamps.
- `pthread_create`: crear un thread.
- `pthread_detach`: separar un thread para no tener que hacer `join`.
- `pthread_join`: esperar a que termine un thread.
- `pthread_mutex_init`: inicializar un mutex.
- `pthread_mutex_destroy`: destruir un mutex cuando ya no se usa.
- `pthread_mutex_lock`: bloquear un mutex antes de acceder a un recurso compartido.
- `pthread_mutex_unlock`: desbloquear un mutex.

## Conceptos clave

- **Thread**: flujo de ejecucion dentro del mismo proceso. En este proyecto,
  normalmente cada filosofo sera un thread.
- **Mutex**: candado para proteger datos compartidos. Si dos threads pueden leer
  o escribir el mismo dato, probablemente necesita proteccion.
- **Race condition**: bug que ocurre cuando varios threads acceden a la misma
  memoria sin sincronizacion correcta.
- **Deadlock**: bloqueo permanente. Por ejemplo, todos los filosofos tienen un
  tenedor y esperan eternamente el segundo.
- **Starvation**: un filosofo no muere por deadlock global, pero nunca consigue
  comer a tiempo.
- **Timestamp**: tiempo en milisegundos desde el inicio de la simulacion.
- **Monitor**: parte del programa que comprueba si alguien ha muerto o si todos
  han comido suficientes veces.

## Lo que hay que construir

- Parsear y validar los argumentos.
- Inicializar filosofos, tenedores y mutexes.
- Lanzar un thread por filosofo.
- Sincronizar el acceso a tenedores y datos compartidos.
- Imprimir los estados sin que los mensajes se mezclen.
- Detectar la muerte de un filosofo a tiempo.
- Terminar correctamente si alguien muere o si se cumple el limite de comidas.
- Liberar memoria y destruir mutexes antes de salir.

Formato de salida:

```text
timestamp_in_ms philosopher_id has taken a fork
timestamp_in_ms philosopher_id is eating
timestamp_in_ms philosopher_id is sleeping
timestamp_in_ms philosopher_id is thinking
timestamp_in_ms philosopher_id died
```

## Casos utiles para probar

```sh
./philo 1 800 200 200
./philo 5 800 200 200
./philo 5 800 200 200 7
./philo 4 410 200 200
./philo 4 310 200 100
```

Nota: revisar siempre el subject oficial del campus antes de entregar, porque
puede haber pequenas diferencias entre versiones.
