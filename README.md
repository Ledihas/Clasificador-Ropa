
# Proyecto Clasificador de Imágenes

<p>

Este proyecto es una aplicación de escritorio desarrollada en C++ utilizando Qt, que permite cargar imágenes y enviarlas a un modelo de inteligencia artificial (IA) implementado en Python con TensorFlow a través de una API Flask. El modelo realiza predicciones basadas en las imágenes cargadas.
</p>

## Tabla de Contenidos

- [Características](#características)
- [Tecnologías Utilizadas](#tecnologías-utilizadas)
- [Instalación](#instalación)
- [Uso](#uso)
- [Contribución](#contribución)
- [Licencia](#licencia)

## Características

- Carga de imágenes en formatos PNG, JPG , JPEG y BMP.
- Envío de imágenes a un modelo de IA para predicciones.
- Visualización de la imagen cargada y el resultado de la predicción.

## Tecnologías Utilizadas

- **C++**: Lenguaje de programación utilizado para la aplicación de escritorio.
- **Qt**: Framework utilizado para desarrollar la interfaz gráfica.
- **Python**: Lenguaje utilizado para implementar el modelo de IA.
- **TensorFlow**: Biblioteca utilizada para construir y entrenar el modelo de IA.
- **Flask**: Framework utilizado para crear la API que sirve como intermediario entre la aplicación Qt y el modelo de IA.

## Instalación

### Requisitos Previos

Asegúrate de tener instalados los siguientes componentes:

- Qt 6.x
- CMake
- Python 3.x
- TensorFlow
- Flask
- Pillow (para manejar imágenes)

### Pasos para la Instalación

1. **Clonar el repositorio**:
   ```bash
   git clone -b main https://github.com/Ledihas/Clasificador-Ropa.git
   cd Clasificador-Ropa
   code .
   
   
   
### Instalar las dependencias de Python:

    ```bash 
    pip install flask tensorflow pillow
    
### Compilar la aplicación Qt:

    ```bash    
    mkdir build
    cd build
    cmake ..
    make

### Ejecutar el servidor Flask:
    ```bash
    python app.py


### Ejecutar la aplicación Qt:
    ```bash
    ./ropero  # Cambia 'ropero' por el nombre real del ejecutable si es diferente.



### Uso:
<ul>
    <li><p>Abre la aplicación.</p></li>
    <li><p>Haz clic en "Cargar Imagen" para seleccionar una imagen desde tu sistema.</p></li>
    <li><p>Haz clic en "Enviar Predicción" para enviar la imagen al modelo y recibir una predicción.</p></li>
    <li><p>La predicción se mostrará en la interfaz.</p></li>
</ul>




### Contribución

**Las contribuciones son bienvenidas. Si deseas contribuir a este proyecto, por favor sigue estos pasos:**

<ul>
   <li><p> Haz un fork del repositorio.</p></li>
    <li><p>Crea una nueva rama (git checkout -b feature/nueva-caracteristica).</p></li>
    <li><p>Realiza tus cambios y haz commit (git commit -m 'Agrega nueva característica').</p></li>
    <li><p>Haz push a la rama (git push origin feature/nueva-caracteristica).</p></li>
    <li><p>Abre un Pull Request.</p></li>
</ul>

<hr>   

