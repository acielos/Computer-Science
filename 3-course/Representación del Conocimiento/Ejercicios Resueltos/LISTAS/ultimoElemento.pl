% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ ULTIMO ELEMENTO ------
%
% Función -> ultimo(?X, ?L)
%
% ***|Se verifica si X unifica con el ultimo
% ***|elemento de la lista L
%
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
ultimo(Ele, [Ele]).

% Hallamos la recursividad
ultimo(Ele, [_|Resto]) :-
    ultimo(Ele, Resto).
