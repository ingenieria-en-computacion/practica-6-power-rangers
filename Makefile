CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Objetivos por estructura
all: circular_queue_linked deque cola_circular_arreglo bicola_arreglo

circular_queue_linked:
	mkdir -p circular_queue_linked/bin
	$(CC) $(CFLAGS) circular_queue_linked/src/main.c circular_queue_linked/src/circular_queue.c -o circular_queue_linked/bin/circular_queue
	@echo "Compilación de circular_queue_linked finalizada"

deque:
	mkdir -p deque/bin
	$(CC) $(CFLAGS) deque/src/main.c deque/src/deque.c -o deque/bin/deque
	@echo "Compilación de deque finalizada"

cola_circular_arreglo:
	mkdir -p "Cola circular con arreglo/bin"
	$(CC) $(CFLAGS) Cola\ circular\ con\ arreglo/src/main.c -o Cola\ circular\ con\ arreglo/bin/cola_circular
	@echo "Compilación de cola_circular_arreglo finalizada"

bicola_arreglo:
	mkdir -p "Bicola con arreglo/bin"
	$(CC) $(CFLAGS) Bicola\ con\ arreglo/src/main.c -o Bicola\ con\ arreglo/bin/bicola
	@echo "Compilación de bicola_arreglo finalizada"

run: all
	@echo "\n=== Ejecutando circular_queue_linked ==="
	@if [ -f "./circular_queue_linked/bin/circular_queue" ]; then ./circular_queue_linked/bin/circular_queue; else echo "Error: No se encuentra el ejecutable circular_queue"; fi
	@echo "\n=== Ejecutando deque ==="
	@if [ -f "./deque/bin/deque" ]; then ./deque/bin/deque; else echo "Error: No se encuentra el ejecutable deque"; fi
	@echo "\n=== Ejecutando cola_circular_arreglo ==="
	@if [ -f "./Cola circular con arreglo/bin/cola_circular" ]; then ./Cola\ circular\ con\ arreglo/bin/cola_circular; else echo "Error: No se encuentra el ejecutable cola_circular"; fi
	@echo "\n=== Ejecutando bicola_arreglo ==="
	@if [ -f "./Bicola con arreglo/bin/bicola" ]; then ./Bicola\ con\ arreglo/bin/bicola; else echo "Error: No se encuentra el ejecutable bicola"; fi

clean:
	rm -f \
		circular_queue_linked/bin/circular_queue \
		deque/bin/deque \
		Cola\ circular\ con\ arreglo/bin/cola_circular \
		Bicola\ con\ arreglo/bin/bicola
	@echo "Archivos binarios eliminados"