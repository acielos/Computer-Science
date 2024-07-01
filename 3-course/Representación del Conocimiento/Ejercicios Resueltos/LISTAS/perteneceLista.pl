% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ RELACION DE PERTENENCIA ------
%
% Función -> pertenece(?X, ?L)
%
% ***|Se verifica si el elemento X pertenece
% ***|a la lista L
%
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
pertenece(Ele, [Ele|_]).

% Hallamos la recursividad
pertenece(Ele, [_|Resto]) :-
    pertenece(Ele, Resto).
