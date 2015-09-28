#ifndef CSGBINAIRE_H
#define CSGBINAIRE_H
#include "csgnode.h"

class CSGBinaire : public CSGNode
{
protected:
    CSGNode * node1;
    CSGNode * node2;

public:
    CSGBinaire(CSGNode *n1, CSGNode *n2);

};

#endif // CSGBINAIRE_H
