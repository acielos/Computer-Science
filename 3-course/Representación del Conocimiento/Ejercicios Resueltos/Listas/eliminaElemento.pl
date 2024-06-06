% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Elimina Elemento -----
% 
% Función -> eliminaElemento(?X, ?List1, ?List2)
%
% ***|Se verifica si List2 unifica con List1 quitando el
% ***|elemento X
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
eliminaElemento(Ele, [Ele|Resto], Resto).

% Hallamos el caso N - 1
eliminaElemento(Ele, [Cab|Resto], [Cab|RestoI]) :- eliminaElemento(Ele, Resto, RestoI).