#ifndef CSGUNAIRE_H
#define CSGUNAIRE_H
#include "csgnode.h"

class CSGUnaire : public CSGNode
{
protected:
    CSGNode * node;

public:
    CSGUnaire(CSGNode *n);

};

#endif // CSGUNAIRE_H
