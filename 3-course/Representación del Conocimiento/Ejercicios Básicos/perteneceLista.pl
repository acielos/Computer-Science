
% pertenece(+Elem, +Lista)
% Es cierto si Elem unifica con algún elemento de Lista

pertenece(Cab, [Cab|_]).
pertenece(N, [Cab|Resto]) :- N \= Cab, pertenece(N, Resto).