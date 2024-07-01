% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ SUBLISTA ------
%
% Función -> sublista(?L1, ?L2)
%
% ***|Se verifica si L2 unifica con una sublista
% ***|de L1
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
sublista([], []).
sublista([_|Resto], Resto).

% Hallamos la recursividad
sublista([Cab|Resto], [Cab|RestoI]) :-
    sublista(Resto, RestoI).

sublista([Cab|Resto], [CabI|RestoI]) :-
    Cab \= CabI,
    sublista(Resto, [CabI|RestoI]).
