% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------------- SUBCONJUNTO -------------
%
% Función -> sub(?L1, ?L2)
%
% ***|Se verifica si L2 unifica con un subconjunto
% ***|de L1
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
sub([], []).
sub(_, []).

% Hallamos la recursividad
sub([Cab|Resto], [Cab|RestoI]) :-
    sub(Resto, RestoI).

sub([Cab|Resto], [CabI|RestoI]) :-
    Cab \= CabI,
    sub(Resto, [CabI|RestoI]).

% ----- FUNCIONES AUXILIARES -----

% --------------------------------------------
% Función ->
%
% ***|Se verifica si
% ***|
% --------------------------------------------



