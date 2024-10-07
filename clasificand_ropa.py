import tensorflow as tf
import tensorflow_datasets as tfds
import matplotlib.pyplot as plt
from tensorflow.keras.preprocessing.image import ImageDataGenerator


# Cargar el conjunto de datos
datos, metadatos = tfds.load('fashion_mnist', as_supervised=True, with_info=True)
datos_entrenamiento, datos_prueba = datos['train'], datos['test']

datos_entrenamiento = datos_entrenamiento.shuffle(60000).batch(32)
datos_prueba = datos_prueba.batch(32)

def resize_images(images, labels, size=(32, 32)):
    return tf.image.resize(images, size), labels

datos_entrenamiento = datos_entrenamiento.map(resize_images)
datos_prueba = datos_prueba.map(resize_images)



# Normalizar las imágenes
datos_entrenamiento = datos_entrenamiento.map(lambda x, y: (x / 255.0, y))
datos_prueba = datos_prueba.map(lambda x, y: (x / 255.0, y))


# Aumentar los datos
datagen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=10,
    width_shift_range=0.2,
    height_shift_range=0.2,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True,
    fill_mode='nearest'
)

def combined_activation(x):
    return tf.keras.activations.tanh(x * (tf.keras.activations.sigmoid(x)))

# Crear el modelo
modelo = tf.keras.models.Sequential([
    tf.keras.layers.Conv2D(32, (3, 3), input_shape=(32, 32, 1), activation= combined_activation),
    tf.keras.layers.MaxPooling2D((2, 2)),
    tf.keras.layers.Conv2D(64, (3, 3), activation= combined_activation),
    tf.keras.layers.MaxPooling2D((2, 2)),
    tf.keras.layers.Conv2D(128, (3, 3), activation= combined_activation),
    tf.keras.layers.MaxPooling2D((2, 2)),
    
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dropout(0.5),
    tf.keras.layers.Dense(100, activation= 'swish'),
    tf.keras.layers.Dense(50, activation= 'swish'),
    tf.keras.layers.Dense(10, activation='softmax')
])

modelo.compile(optimizer="adam", loss="sparse_categorical_crossentropy", metrics=["accuracy"])

from tensorflow.keras.callbacks import TensorBoard

tensorConv = TensorBoard(log_dir='logs/modelo')

print("Entrenando Modelo")

# Entrenar el modelo con el generador de datos
history = modelo.fit(datos_entrenamiento,
                       epochs=6,
                       validation_data=datos_prueba,
                       callbacks=[tensorConv],
                       verbose=1)

modelo.save("save_models/ropa.h5")
print("Modelo Guardado")

# Opcional: Graficar la evolución de la pérdida durante el entrenamiento
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title('Progreso de Pérdida durante Entrenamiento del Modelo')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
plt.show()
