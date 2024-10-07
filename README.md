
# Proyecto Clasificador de Imágenes

<p>

Este proyecto es una aplicación de escritorio desarrollada en C++ utilizando Qt, que permite cargar imágenes y enviarlas a un modelo de inteligencia artificial (IA) implementado en Python con TensorFlow a través de una API Flask. El modelo realiza predicciones basadas en las imágenes cargadas.En el proyecto se puede ver un módulo de Python 'llamado clasificand_ropa.py' en el cual esta impementado el codigo con el que se entrenó el modelo; el cual utiliza TensorFlow y el conjunto de datos Fashion MNIST. El modelo se entrena para clasificar imágenes de ropa en diferentes categorías utilizando una red neuronal convolucional (CNN).

</p>

## Tabla de Contenidos

- [Características](#características)
- [Características de clasificand_ropa.py](#características-de-clasificand_ropa.py)
- [Tecnologías Utilizadas](#tecnologías-utilizadas)
- [Instalación](#instalación)
- [Uso](#uso)
- [Uso de clasificand_ropa.py para entrenar un modelo](uso-de-clasificand_ropa.py-para-entrenar-un-modelo)
- [Contribución](#contribución)
- [Licencia](#licencia)

## Características

- Carga de imágenes en formatos PNG, JPG , JPEG y BMP.
- Envío de imágenes a un modelo de IA para predicciones.
- Visualización de la imagen cargada y el resultado de la predicción.


## Características de clasificand_ropa.py

- Carga y preprocesamiento del conjunto de datos Fashion MNIST.
- Normalización y aumento de datos para mejorar el rendimiento del modelo.
- Implementación de una red neuronal convolucional (CNN).
- Entrenamiento del modelo con visualización de la pérdida durante el entrenamiento.
- Guardado del modelo entrenado para su uso posterior.

## Tecnologías Utilizadas

- **C++**: Lenguaje de programación utilizado para la aplicación de escritorio.
- **Qt**: Framework utilizado para desarrollar la interfaz gráfica.
- **Python**: Lenguaje utilizado para implementar el modelo de IA.
- **TensorFlow**: Biblioteca utilizada para construir y entrenar el modelo de IA.
- **Flask**: Framework utilizado para crear la API que sirve como intermediario entre la aplicación Qt y el modelo de IA.
- **TensorFlow Datasets**: Para cargar conjuntos de datos fácilmente.
- **Matplotlib**: Para visualizar la evolución de la pérdida durante el entrenamiento.

## Instalación

### Requisitos Previos

Asegúrate de tener instalados los siguientes componentes:

- Qt 6.x
- CMake
- Python 3.x
- TensorFlow
- Flask
- Pillow (para manejar imágenes)
- TensorFlow Datasets
- Matplotlib

### Pasos para la Instalación

1. **Clonar el repositorio**:
   ```bash
   git clone -b main https://github.com/Ledihas/Clasificador-Ropa.git
   cd Clasificador-Ropa
   code .
   
   
### Crear un entorno virtual (opcional pero recomendado):

      ```bash
      python -m venv venv
      source venv/bin/activate  # En Linux/Mac
      venv\Scripts\activate  # En Windows

### Instalar las dependencias de Python:

    ```bash 
    pip install flask tensorflow pillow tensorflow-datasets matplotlib

    
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

### Uso de clasificand_ropa.py para entrenar un modelo:
<ul>
    <li><p>Asegúrate de que tienes todas las dependencias instaladas.</p></li>
    <li><p>Ejecuta el script: python clasificand_ropa.py.py</p></li>
    <li><p>El modelo se entrenará y se guardará en la carpeta 'save_models' como 'opa.h5'.</p></li>
    <li><p>Se generará un gráfico que muestra la evolución de la pérdida durante el entrenamiento.</p></li>
</ul>

### Estructura de clasificand_ropa.py
El código principal realiza las siguientes tareas:

-Carga del conjunto de datos: Utiliza tensorflow_datasets para cargar Fashion MNIST.
-Preprocesamiento: Redimensiona las imágenes, normaliza los valores y aplica aumentos a los datos.
-Definición del modelo: Crea una red neuronal convolucional con varias capas.
-Entrenamiento: Entrena el modelo utilizando los datos preprocesados y valida su rendimiento.
-Visualización: Muestra la evolución de la pérdida durante el entrenamiento.



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

