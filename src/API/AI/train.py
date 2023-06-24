import os

import numpy as np
import tensorflow as tf
from tensorflow import keras

save = True
train = True

# Data

mnist = keras.datasets.mnist
(x_train, y_train), (x_test, y_test) = mnist.load_data()  # get training and test data
x_train, x_test = x_train/255.0, x_test/255.0  # normalizing values
x_train, x_test = np.expand_dims(x_train, axis=-1), np.expand_dims(x_test, axis=-1)
# add dimension for training in cnn

# Training model
inputs = keras.layers.Input(shape=(28, 28, 1))
# input dimension is 28x28 image, add 1 for cnn
c = keras.layers.Conv2D(32, (3, 3), padding="valid", activation=tf.nn.relu)(inputs)
# 32 filters of size 3x3, adding 0's in border to avoid shrinking dimension of image
m = keras.layers.MaxPool2D((2, 2), (2, 2))(c)
# max pooling after filter
d = keras.layers.Dropout(0.55)(m)
# dropout higher in beginning, avoid too much generalization
c = keras.layers.Conv2D(64, (3, 3), padding="valid", activation=tf.nn.relu)(d)
m = keras.layers.MaxPool2D((2, 2), (2, 2))(c)
d = keras.layers.Dropout(0.5)(m)
# latest layer has higher level abstraction, has lower dropout
c = keras.layers.Conv2D(128, (3, 3), padding="valid", activation=tf.nn.relu)(d)
f = keras.layers.Flatten()(c)
outputs = keras.layers.Dense(10, activation=tf.nn.softmax)(f)
# softmax for multiclass logistic regression

model = keras.models.Model(inputs, outputs)
model.compile(optimizer="adam",
                loss="sparse_categorical_crossentropy",
                metrics=["accuracy"])


if __name__ == '__main__':
    if train:
        model.fit(x_train, y_train, epochs=5)
        test_loss, test_acc = model.evaluate(x_test, y_test)
        print("Test Loss: {0} - Test Acc: {1}".format(test_loss, test_acc))
    if save:
        saved_model = model.save("weights/model.h5")

