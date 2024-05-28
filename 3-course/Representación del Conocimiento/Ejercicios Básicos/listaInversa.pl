
% reverse(+List, -ListaR)
% ListR unifica con una lista que contiene los mismos elementos que List pero en orden inverso

reverse([],[]).

reverse([Cab|Resto], L2) :- reverse(Resto, L), append(L, [Cab], L2).