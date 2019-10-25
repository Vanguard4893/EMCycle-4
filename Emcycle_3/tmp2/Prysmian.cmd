;;Digital outputs status		DIGOP		(1=active)
;;	equ	0	;bit 0 of DIGOP =
;	equ	1	;bit 1 of DIGOP = 
;OC2	equ	2	;bit 2 of DIGOP = Open collector output 2
;OC1	equ	3	;bit 3 of DIGOP = Open collector output 1
;RLY2	equ	4	;bit 4 of DIGOP = Relay 2
;RLY1	equ	5	;bit 5 of DIGOP = Relay 1
;ANO2	equ	6	;bit 6 of DIGOP = Analogue output 2
;ANO1	equ	7	;bit 7 of DIGOP = Analogue output 1
;
;
;
;
;DLAY 1		; Wait at initial state
;STAT		;check status
;DIGO 08		;transmit signal - digital output - OC1 & RLY1
;DLAY 1		; Wait for the preceding commands to be carried out
;STAT
;check status
;DIGO 04		;reset signal - digital output - OC2 & RLY2
;DLAY 1		; Wait for the preceding commands to be carried out
;STAT		;check status
;DIGO 00		;clear outputs
;DLAY 1		; Wait for the preceding commands to be carried out
;STAT		;check status
DIGO 00		;clear outputs
DLAY 4		; Wait at initial state
DIGO 04		;Initiate alarm
DLAY 1		; Wait for the preceding commands to be carried out
DIGO 00		;clear outputs
DLAY 4		; Wait for the preceding commands to be carried out
DIGO 08		;system reset
DLAY 1		; Wait for the preceding commands to be carried out
DIGO 00		;clear outputs
