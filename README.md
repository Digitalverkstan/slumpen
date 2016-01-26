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

### Mål

När vi är klara ska vi ha sex lysdioder på rad. När man trycker ner knappen ska dioderna slockna, och ett nytt tal slumpas fram, när man släpper knappen ska så många dioder lysa som det slumpade talet.


### Bygg

Fritzing-schemat stämmer inte riktigt eftersom en komponent saknas - resistorskenan.
En resistorskena är ett gäng resistorer med samma värde (8 st i vårt fall) som är sammankopplade på ena sidan. Den komponenten gör det väldigt lätt att använda många lysdioder med få kablar. Nedan ser du ett schema för hur en resistorskena är byggd, och hur komponenten ser ut i den färdiga kretsen.

![Schema för resistorskena](https://github.com/Digitalverkstan/slumpen/blob/master/img/resistor_network.png)

![Kretsen](https://github.com/Digitalverkstan/slumpen/blob/master/img/circuit.png)

Koppla upp kretsen och kom ihåg att det är en kabel per lysdiod, så det blir mycket kablar. På fotografiet kan man se en vit och en gul kabel som är kopplade till änden av resistorskenan, den gula kabeln går till jord - och det är den gemensamma jordpunkten både för knappen och för lysdioderna.

### Kod

_Färdigt kodexempel med kommentarer finns i filen_ `slumpen.ino`

Vi ska sätta igång och stänga av flera lysdioder samtidigt, och dessutom olika många vid olika tillfällen - därför använder vi `for`-loopar.

En loop gör samma sak ett visst antal gånger och ändrar en variabel varje gång den gör vad den ska. Den variabeln heter oftast något väldigt kort, till exempel `i`, `j`, `x` eller `y` och kan bara användas inuti loopen.

Exempel:

    for(int i = 0; i < 10; i++) {
        print(i);
    }

Loopen använder variabeln `i` som första gången har värdet 0. Loopen körs så länge i är mindre än 10, och varje gång ökas `i` med 1 (det är vad `i++` betyder). Det som händer i loopen är att `i` printas och det borde se ut såhär, 0 är med men 10 är inte med.

    0123456789

Här ska vi använda loopar för att styra flera lysdioder samtidigt, därför har vi kopplat dem till portar som ligger precis bredvid varandra. Vi börjar med att förbereda portarna, lysdioderna är kopplade på port 2 till 7, låt `i` peka på portarnas nummer:

    void setup() {
        for(int i = 2; i <= 7; i++) {
            pinMode(i, OUTPUT);
        }
    }

Förbered även knappen och en variabel som ska hålla koll på det slumpade talet. Knappens portnummer är 8, och variabeln ska vara en `int`

    int slump;

    void setup() {
        for(int i = 2; i <= 7; i++) {
            pinMode(i, OUTPUT);
        }

        pinMode(8, INPUT_PULLUP)
        slump = 0;
    }

Nu är det dags för loop-funktionen, vi har två saker som ska hända. 1 - när man trycker ner knappen ska lydioderna slockna och ett nytt tal slumpas fram. `random(6)` ger oss ett tal mellan 0 och 5. Släck alla lysdioder med en `for`-loop.

    void loop() {
        if(digitalRead(8) == LOW) {
            slump = random(6);
            for(int i = 2; i <= 7; i++) {
                digitalWrite(i, LOW);
            }

            delay(10)
        }
    }

När knappen är uppe ska vi visa så många lysdioder som vi slumpade fram. Nu är slumptalet mellan 0 och 5, men vi ser till att det blir 1 - 6 istället. Vi låter helt enkelt en lysdiod lysa varje gång.

    void loop() {
        if(digitalRead(8) == LOW) {
            slump = random(6);
            for(int i = 2; i <= 7; i++) {
                digitalWrite(i, LOW);
            }

            delay(10)
        } else {

            for(int i = 2; i <= slump+2; i++) {
                digitalWrite(i, HIGH);
            }
        }
    }

Testa matematiken: Om `slump` är 0 så körs loopen när `i` är 2 eftersom 0 + 2 = 2, och `2 <= 2` är sant. Om `slump` är 5 så körs loopen när `i` är 2,3,4,5,6,7 eftersom `i <= 5 + 2` är samma sak som `i <= 7` och det är sant för alla siffror mellan 2 och 7.

Skicka till arduinon och testa! Om allt är kopplat på rätt sätt och koden inte har några fel så ska allt fungera.

Bra jobbat!
