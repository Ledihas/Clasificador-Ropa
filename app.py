from flask import Flask, request, jsonify
import tensorflow as tf
import numpy as np
from PIL import Image
from tensorflow.keras import activations


def combined_activation(x):
    return activations.tanh(x * activations.sigmoid(x))


model = tf.keras.models.load_model('modelo/ropa.h5', custom_objects= {'combined_activation': combined_activation})  # Especifica la ruta a tu modelo

app = Flask(__name__)

@app.route('/predict', methods=['POST'])
def predict():
    # Obtener la imagen del cuerpo de la solicitud
    file = request.files['image']
    
    # Leer la imagen y convertirla a un array numpy
    img = Image.open(file.stream).convert('L')  # Convertir a escala de grises
    img = img.resize((32, 32))  # Redimensionar a 100x100
    input_data = np.array(img).reshape(1, 32, 32, 1)  # Ajustar la forma según el modelo

    # Normalizar los datos si es necesario (por ejemplo, dividir por 255)
    input_data = input_data / 255.0

    # Realizar la predicción
    prediction = model.predict(input_data)

    # Suponiendo que el modelo devuelve una lista de probabilidades
    predicted_class = np.argmax(prediction)  # Obtener la clase con mayor probabilidad
    
    return jsonify({"predicted_class": int(predicted_class), "probabilities": prediction.tolist()})


if __name__ == '__main__':
    app.run(debug=True)