% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Concatenación de Listas -----
% 
% Función -> concatena(?L1, ?L2, ?L3)
%
% ***|Se verifica si L3 unifica con la lista obtenida de
% ***|añadir los elementos de L2 al final de la lista L1
%
%------------------------------------

% Principio de Inducción
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
concatena([], Lista, Lista).

% Hallamos el caso N - 1
concatena([Cab|Resto], L2, [Cab|RestoII]) :- concatena(Resto, L2, RestoII).