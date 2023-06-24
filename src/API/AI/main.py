"""
Prend le chemin de l'image en paramètre du programme lors de l'exécution de celui-ci
Retourne le numéro reconnu en code de sortie du programme (on peut regarder lequel c'était avec `echo $?` dans le shell)
"""

from warnings import catch_warnings
import tensorflow
from tensorflow import keras as kr
import numpy as np
import sys
from PIL import Image, ImageOps
import os

ERROR = {
    "FILETYPE": 10, 
    "NO PARAMS": 11, 
    "EXECUTION ERROR": 12
} # Code d'erreurs pour s'y retrouver dans les codes de retour

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Program only launch with parameters: python3 main.py file.png")
        exit(ERROR["NO PARAMS"])
    PATH_TO_IMAGE = sys.argv[-1]

    try:
        model = kr.models.load_model('./weights/model.h5')  # load trained model

        im = Image.open(PATH_TO_IMAGE).resize(size=(28, 28))
        im = ImageOps.grayscale(im)  # black and white scaling
        data = 1 - np.asarray(im.getdata()) / 255.0  # normalizing pixel values
        data = data.reshape((1, 28, 28, 1))  # input shape of CNN
        result = int(np.argmax(model.predict(data)))  # index of highest proba is outcome
        print("Numéro trouvé:",result)
    except:
        result = ERROR["EXECUTION ERROR"]
        print(result)
    

    exit(result)