% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- SUBCONJUNTO -----
% 
% Función -> subconjunto(+Lis1, ?Lis2)
%
% ***|Se verifica si Lis2 unifica con un subconjunto de Lis1
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
subconjunto([X, Y|_], [X, Y]).

% Hallamos el caso N - 1
subconjunto([_, CabI|Resto], Lis2) :- subconjunto([CabI|Resto], Lis2).