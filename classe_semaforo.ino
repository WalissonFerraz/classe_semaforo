#define ledR 8
#define ledY 9
#define ledG 10

class Semaforo {
public:
  Semaforo(int pr, int py, int pg)
    : pinR(pr), pinY(py), pinG(pg) {
    padaoAtraso();
  }

  void ligaSemaforo() {
    trocaCor(1, 0, 0);
    delay(dR);
    trocaCor(0, 1, 0);
    delay(dY);
    trocaCor(0, 0, 1);
    delay(dG);
  }

  void delayConf(int deR, int deY, int deG) {
    dR = deR;
    dY = deY;
    dG = deG;
  }

private:
  int pinR, pinY, pinG, dR, dY, dG, cor;

  void trocaCor(int r, int y, int g) {
    digitalWrite(pinR, r);
    digitalWrite(pinY, y);
    digitalWrite(pinG, g);
  }

  void padaoAtraso() {
    dR = 5000;
    dY = 1000;
    dG = 5000;
  }
};

Semaforo sem1(ledR, ledY, ledG);

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  sem1.delayConf(4000, 1500, 5000);
}

void loop() {
  sem1.ligaSemaforo();
}
