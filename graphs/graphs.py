    #!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Implémentation d'un graphe non orienté à l'aide d'un dictionnaire: les clés
sont les sommets, et les valeurs sont les sommets adjacents à un sommet donné.
Les boucles sont autorisées. Les poids ne sont pas autorisés.

On utilise la représentation la plus simple: une arête {u, v} sera présente
deux fois dans le dictionnaire: v est dans l'ensemble des voisins de u, et u
est dans l'ensemble des voisins de v.
"""


class GrapheOriente(object):
    def __init__(self):
        """Initialise un graphe sans arêtes"""
        self.dictionnaire = dict()

    def ajouter_arc(self, u, v):
        """Ajoute une arête entre les sommmets u et v, en créant les sommets
        manquants le cas échéant."""
        # vérification de l'existence de u et v, et création(s) sinon
        if u not in self.dictionnaire:
            self.dictionnaire[u] = set()
        if v not in self.dictionnaire:
            self.dictionnaire[v] = set()
        # ajout de u (resp. v) parmi les voisins de v (resp. u)
        self.dictionnaire[u].add(v)

    def ajouter_arcs(self, iterable):
        """Ajoute toutes les arêtes de l'itérable donné au graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples d'éléments (quel que soit le type du couple)."""
        for u, v in iterable:
            self.ajouter_arc(u, v)

    def ajouter_sommet(self, sommet):
        """Ajoute un sommet (de n'importe quel type hashable) au graphe."""
        self.dictionnaire[sommet] = set()

    def ajouter_sommets(self, iterable):
        """Ajoute tous les sommets de l'itérable donné au graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des éléments hashables."""
        for sommet in iterable:
            self.ajouter_sommet(sommet)

    def arcs(self):
        """Renvoie l'ensemble des arêtes du graphe. Une arête est représentée
        par un tuple (a, b) avec a <= b afin de permettre le renvoi de boucles.
        """
        return {
            tuple((u, v)) for u in self.dictionnaire
            for v in self.dictionnaire[u]
        }

    def boucles(self):
        """Renvoie les boucles du graphe, c'est-à-dire les arêtes reliant un
        sommet à lui-même."""
        return {(u, u) for u in self.dictionnaire if u in self.dictionnaire[u]}

    def contient_arc(self, u, v):
        """Renvoie True si l'arête {u, v} existe, False sinon."""
        if self.contient_sommet(u) and self.contient_sommet(v):
            return u in self.dictionnaire[v]  # ou v in self.dictionnaire[u]
        return False

    def contient_sommet(self, u):
        """Renvoie True si le sommet u existe, False sinon."""
        return u in self.dictionnaire

    def degre(self, sommet):
        """Renvoie le nombre de voisins du sommet; s'il n'existe pas, provoque
        une erreur."""
        return len(self.dictionnaire[sommet])

    def nombre_arcs(self):
        """Renvoie le nombre d'arêtes du graphe."""
        return len(self.arcs())

    def nombre_boucles(self):
        """Renvoie le nombre d'arêtes de la forme {u, u}."""
        return len(self.boucles())

    def nombre_sommets(self):
        """Renvoie le nombre de sommets du graphe."""
        return len(self.dictionnaire)

    def retirer_arc(self, u, v):
        """Retire l'arête {u, v} si elle existe; provoque une erreur sinon."""
        self.dictionnaire[u].remove(v)  # plante si u ou v n'existe pas
        # plante si u ou v n'existe pas

    def retirer_arcs(self, iterable):
        """Retire toutes les arêtes de l'itérable donné du graphe. N'importe
        quel type d'itérable est acceptable, mais il faut qu'il ne contienne
        que des couples d'éléments (quel que soit le type du couple)."""
        for u, v in iterable:
            self.retirer_arc(u, v)

    def retirer_sommet(self, sommet):
        """Efface le sommet du graphe, et retire toutes les arêtes qui lui
        sont incidentes."""
        del self.dictionnaire[sommet]
        # retirer le sommet des ensembles de voisins
        for u in self.dictionnaire:
            self.dictionnaire[u].discard(sommet)

    def retirer_sommets(self, iterable):
        """Efface les sommets de l'itérable donné du graphe, et retire toutes
        les arêtes incidentes à ces sommets."""
        for sommet in iterable:
            self.retirer_sommet(sommet)

    def successeurs(self, sommet):
        return sorted( [i for i in self.dictionnaire[sommet]])
        
    def predecesseurs(self, sommet):
        res = []
        for v in self.dictionnaire:
            if sommet in self.dictionnaire[v]:
                res.append(v)

        return res
    
    def degre_entrant(self, sommet):
        return len(self.predecesseurs(sommet))
        
    def degre_sortant(self, sommet):
        return len(self.successeurs(sommet))
    
    def sommets(self):
        """Renvoie l'ensemble des sommets du graphe."""
        return set(self.dictionnaire.keys())

    def sous_graphe_induit(self, iterable):
        """Renvoie le sous-graphe induit par l'itérable de sommets donné."""
        G = GrapheOriente()
        G.ajouter_sommets(iterable)
        for u, v in self.arcs():
            if G.contient_sommet(u) and G.contient_sommet(v):
                G.ajouter_arc(u, v)
        return G

    def voisins(self, sommet):
        """Renvoie l'ensemble des voisins du sommet donné."""
        return self.dictionnaire[sommet]

def aux1(graphe, depart, d_v, parents):
    resultat = list()
    d_v[depart]=1
    for v in graphe.successeurs(depart):
        if d_v[v]!=1:
            resultat+=aux1(graphe,v,d_v,parents)
            parents[v]=depart
    resultat.append(depart)
    return resultat
    
def parcours_profondeur_oriente(graphe):
    d_v={u:0 for u in graphe.sommets()}
    parents=dict()
    depart=list(graphe.sommets())[0]
    sommets = aux1(graphe, depart, d_v, parents)
    for v in graphe.sommets():
        if d_v[v]!=1:
            sommets += aux1(graphe, v, d_v, parents)
    return (sommets, parents)
    
def test_suite(graphe, u):
    for i, j in graphe.arcs():
        if u == j:
            return True
    return False


def nettoyer_cycle(graphe):
    for u,v in graphe.arcs():
        if not test_suite(graphe, u):
            graphe.retirer_arc(u, v)

def aux2(graphe, sommet, status, cycle):
	if status[sommet]==1:
		return True
	if status[sommet]==0: 
		return False
	status[sommet]=1
	for v in graphe.successeurs(sommet):
		if aux2(graphe, v, status, cycle):
			cycle.ajouter_arc(sommet,v)
			return True
	status[sommet]=0
	return False

def detection_cycle(graphe):
	status={u:-1 for u in graphe.sommets()}
	cycle=type(graphe)()
	for u in graphe.sommets():
		if aux2(graphe, u, status, cycle) == True :
			nettoyer_cycle(cycle)
			return cycle
			
def parcours_profondeur_oriente_date(graphe,depart,dates,instant):
    dates[depart] = 0
    for v in graphe.successeurs(depart):
        if(dates[v] == -1):
            parcours_profondeur_oriente_date(graphe ,v, dates,instant)
    dates[depart] =instant[0]
    instant[0] += 1
    
def profondeur_dates(graphe):
    dates = dict()
    instant = dict()
    instant[0] = 1
    for sommet in graphe.sommets():
        dates[sommet] =  -1
    for v in graphe.sommets():
        if(dates[v] == -1):
            parcours_profondeur_oriente_date(graphe,v,dates,instant)
    return dates
        
def renversement(graphe):
    graphe_bis = GrapheOriente()
    ensemble = graphe.arcs()
    for v in ensemble:
        graphe_bis.ajouter_arc(v[1] , v[0])
    return graphe_bis

def parcours_profondeur_oriente_rec(graphe,depart,deja_visites):
    sommets = list()
    deja_visites[depart] = True
   
    for v in graphe.successeurs(depart):
        if(not deja_visites[v]):
           
            sommets += (parcours_profondeur_oriente_rec(graphe ,v, deja_visites))
    sommets.append(depart)
   
    return sommets

    
def composantes_fortement_connexes(graphe):
    CFC = list()
    deja_visites = dict()
    dates = dict()
 
    dates = profondeur_dates(graphe)
   
    graphe_bis = renversement(graphe)
    for sommet in graphe.sommets():
        deja_visites[sommet] = False
    sommets = sorted(dates.items(), key=lambda colonne: colonne[1] , reverse = True)
    for v in sommets:
        if(not deja_visites[v[0]]):
            deja_visites[v[0]] = True
            CFC.append(parcours_profondeur_oriente_rec(graphe_bis,v[0],deja_visites))
    return CFC