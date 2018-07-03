import openturns as ot

class OpenTURNSPythonFieldFunction(object):
    def __init__(self):
        self.__mesh = ot.Mesh()
    def getInputMesh(self):
        return self.__mesh

obj = OpenTURNSPythonFieldFunction()

f = ot.FieldFunction(obj)
print('OK')

