% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% --------------- IGUALES ---------------
%
% Función -> iguales(+L)
%
% ***|Se verifica si todos los elementos de L
% ***|son iguales
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
iguales([_]).

% Hallamos la recursividad
iguales([Cab, Cab|Resto]) :-
    iguales([Cab|Resto]).
