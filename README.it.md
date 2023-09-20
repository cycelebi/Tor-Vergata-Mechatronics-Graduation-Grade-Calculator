[![en](https://img.shields.io/badge/lang-english-yellow.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.md)
[![it](https://img.shields.io/badge/lang-italiano-white.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.it.md)
[![tr](https://img.shields.io/badge/lang-türkçe-red.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.tr.md)
[![ru](https://img.shields.io/badge/lang-русский-blue.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.ru.md)

# Calcolatore del voto di Laurea Magistrale in Ingegneria Meccatronica Tor Vergata

## Introduzione

Questo progetto di programmazione C è stato sviluppato da Mehmet Celebi per il corso di Progettazione di Sistemi Circuiti VLSI presso l'Università di Roma "Tor Vergata". Il progetto si concentra sulla creazione di un programma che consente agli utenti di inserire e calcolare voti e crediti per i loro corsi, nonché determinare lo stato di laurea.

## Struttura del programma

Il programma è strutturato come segue:

- Il programma inizia includendo la libreria necessaria, `stdio.h`, per l'input e l'output standard.
- Il programma definisce una struttura chiamata "Corso", che rappresenta un corso e contiene attributi come il nome del corso, i crediti CFU, il voto e lo stato di lode.
- La funzione principale inizializza variabili e un array di strutture per memorizzare le informazioni sui corsi.
- Il programma entra in un ciclo while per raccogliere informazioni su ciascun corso dall'utente. Il ciclo consente all'utente di aggiungere o eliminare corsi secondo necessità.
- All'interno del ciclo, il programma richiede all'utente di inserire il nome del corso, i CFU, il voto e lo stato di lode. Verifica gli input e li memorizza nella struttura corrispondente.
- Dopo aver raccolto tutte le informazioni sui corsi, il programma calcola il voto ponderato totale, i CFU totali e i bonus di lode totali.
- Il programma visualizza quindi i dettagli del corso, tra cui il nome del corso, i CFU, il voto e lo stato di lode.
- Infine, il programma calcola la media ponderata dei voti, verifica la presenza di ulteriori bonus e determina lo stato di laurea.

## Calcoli e Formule

Il programma esegue i seguenti calcoli:

- Voto Ponderato: Il programma calcola il voto ponderato per ogni corso moltiplicando il voto per i CFU e sommando i risultati. Il voto ponderato totale viene quindi diviso per i CFU totali per ottenere il voto ponderato complessivo.
    
    Formula: `votoPonderato = votoTotale / CFUtotale`
    
- Bonus di Lode: Il programma verifica i corsi con 9 o 12 CFU e uno stato di lode pari a 1 (con lode). Conta il numero di corsi che soddisfano questi criteri e assegna un bonus di lode di conseguenza.
- Punteggio di Laurea: Il programma calcola il punteggio di laurea moltiplicando la media ponderata dei voti per un fattore di conversione di 110/30, aggiungendo i bonus di lode, lo stato di laurea in tempo e il punteggio della tesi (se applicabile).
    
    Formula: `punteggioLaurea = (votoPonderato * 110/30) + lodeTotale + inTempo + tesi`
    
- Formula tratta dal [sito web dell'Università di Roma Tor Vergata](http://mechatronics.uniroma2.it/wp-content/uploads/2021/02/Calculation-marks-for-the-Master.pdf). Le modifiche possono essere apportate nel tempo.

## Stato di Laurea

Il programma determina lo stato di laurea in base al punteggio di laurea:

- Cum Laude: Se il punteggio di laurea è 110 o superiore, il programma dichiara lo studente idoneo a laurearsi con lode.
- Cum Laude per decisione del Consiglio: Se il punteggio di laurea è compreso tra 104 e 109, il programma indica che lo studente potrebbe essere idoneo a laurearsi con lode per decisione del Consiglio.
- Idoneo a Laurearsi: Se il punteggio di laurea è uguale o superiore a 66, il programma dichiara lo studente idoneo a laurearsi.
- Non Idoneo a Laurearsi: Se il punteggio di laurea è inferiore a 66, il programma dichiara lo studente non idoneo a laurearsi.

## Conclusioni

Questo progetto di programmazione C consente agli utenti di inserire e calcolare voti e crediti per i loro corsi, nonché determinare il loro stato di laurea. Fornisce un modo completo ed efficiente per gestire ed valutare le prestazioni accademiche.
