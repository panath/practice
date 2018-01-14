class Vertex:
    def __init__(self, key):
       self.id = key
       self.connectedTo = {}

    def addNeighbor(self, nbr, weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])
    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self, nbr):
        return self.connectedTo[nbr]

    def getWeight(self, nbr):
        return self.connectedTo[nbr]


if __name__ == "__main__":
    v = Vertex(1)
    v.addNeighbor(3)
    assert 1, v.getId()
    assert 1, v.getConnections()
