% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- INSERTAR ELEMENTO -----
% 
% Función -> insertaElmento(?X, ?Lis1, ?Lis2)
%
% ***|Se verifica si Lis2 unifica con la lista Lis1 insertando el
% ***|elemento X.
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
insertaElemento(Cab, [], [Cab]).

% Hallamos el caso N - 1
insertaElemento(Ele, Lis1, Lis2) :- append(Lis1, [Ele], Lis2).