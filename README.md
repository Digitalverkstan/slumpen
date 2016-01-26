# Slumpen
Ett arduinoprojekt för en digital tärning

### Använder

 * LED & resistor
 * Tryckknapp
 * For-loopar

### Komponentlista

 * Arduino & utvecklingsdator
 * 1 st liten kopplingsbräda
 * 6 st LED
 * 1 st Resistorskena 8x (Resistor network) ~ 300 Ohm
 * 1 st Tryckknapp (momentan)
 * 9 st kopplingskabel (hane - hane)

### Bygg

Fritzing-schemat stämmer inte riktigt eftersom en komponent saknas - resistorskenan.
En resistorskena är ett gäng resistorer med samma värde (8 st i vårt fall) som är sammankopplade på ena sidan. Den komponenten gör det väldigt lätt att använda många lysdioder med få kablar. Nedan ser du ett schema för hur en resistorskena är byggd, och hur komponenten ser ut i den färdiga kretsen.

![Schema för resistorskena](https://github.com/Digitalverkstan/slumpen/blob/master/img/resistor_network.png)

![Kretsen](https://github.com/Digitalverkstan/slumpen/blob/master/img/circuit.png)

Koppla upp kretsen och kom ihåg att det är en kabel per lysdiod, så det blir mycket kablar. På fotografiet kan man se en vit och en gul kabel som är kopplade till änden av resistorskenan, den gula kabeln går till jord - och det är den gemensamma jordpunkten både för knappen och för lysdioderna.
