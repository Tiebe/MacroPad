# Macro Pad

## wat willen we in dit project hebben?

### programming

- remote control gordijnen
- remote control beamer (low priority)
- knopjes + manier zeggen wat knopjes doen
- api (priority unknown)
- project structure (doet tiebe als ik dat niet erg vind)
- mode switching

### not programming

- 3d print case (beetje snel wel)



## soldeer notes

### safety switch

**Ignore this, tiebe stupid**
- ground verbinden met vierkant
- plus verbinden met ronde


# afmeting 
total length: 70.60 mm
switch length: 14 mm
beam length: (70.6 - 4(14))/3 = 4+(13/15) ≈ 4.86 mm


## Bugs
- writeLedState gets called on rising and falling edge, should only be on rising edge.
- Only the first mode that gets added to buttonModes gets switched to.