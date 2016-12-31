# Clue Solver

**Solver for the board game Clue.**

*Clue Solver* is intended to be used during a Clue play to help the user in playing better match by providing deductions. The user, by means of the GUI, is supposed to continously insert new information in *Clue Solver* (e.g.: which cards are searched by another player during an inquery phase and which player showed him a card, etc.) to allow *Clue Solver* to continuously make deductions about the play (e.g.: understand which cards are held by a certain adversary player, etc.); the user can also use the GUI to check which deductions *Clue Solver* has successfully made up to now, so that he can use this knowledge to play better during his turns (e.g.: make better inqueries, decide which room is more convient for him to reach, etc.).

A sketch of the game rules can be found on Wikipedia: <https://en.wikipedia.org/wiki/Cluedo>. It is assumed that the players will use the rules of the classical version of the game (at the moment *Clue Solver* does not support variants).

Note: the official name of the software program is *Clue Solver*, but to avoid problems with the space character in the name during computations, the Qt project and the GitHub repository are named *Clue_Solver* (i.e., an underscore replaces the space).
