import openturns as ot

class OpenTURNSFieldFunction(object):
    def __init__(self):
        #super(OpenTURNSFieldFunction).__init__(self)
        self.__mesh = ot.Mesh()
    def getInputMesh(self):
        return self.__mesh

obj = OpenTURNSFieldFunction()

f = ot.FieldFunction(obj)
print('OK')

