//Press Ctrl+Shift+M to get IP Adress
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Root";
const char* password = "#the_fitzac_1924";

ESP8266WebServer server(80);

const int output1 = D0;//D5
const int output2 = D1;//D6

boolean device1 = false;
boolean device2 = false;

void handleRoot() {

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      
      if(device1){
        cmd +=("Device1  : ON");
        digitalWrite(output1, LOW); 
        device1 = true;
      }
      else{
        cmd +=("Device1  : OFF");
        digitalWrite(output1, HIGH); 
        device1 = false;
      }
      
      if(device2){
        cmd +=("<br/>Device2  : ON");
        digitalWrite(output2, LOW); 
        device2 = true;
      }
      else{
        cmd +=("<br/>Device2  : OFF");
        digitalWrite(output2, HIGH); 
        device2 = false;
      }
      cmd += "<br/><a href=\"/status1=1\"\"><button>LED1 On </button></a>";
      cmd += "<a href=\"/status1=0\"\"><button>LED1 Off </button></a><br />";
      cmd += "<a href=\"/status2=1\"\"><button>LED2 On </button></a>";
      cmd += "<a href=\"/status2=0\"\"><button>LED2 Off </button></a><br />";
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}

void led1on() {

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      cmd +=("Device1  : ON");
      digitalWrite(output1, LOW); 
      device1 = true;
      
      if(device2){
        cmd +=("<br/>Device2  : ON");
        digitalWrite(output2, LOW); 
        device2 = true;
      }
      else{
        cmd +=("<br/>Device2  : OFF");
        digitalWrite(output2, HIGH); 
        device2 = false;
      }
      cmd += "<br/><a href=\"/status1=1\"\"><button>LED1 On </button></a>";
      cmd += "<a href=\"/status1=0\"\"><button>LED1 Off </button></a><br />";
      cmd += "<a href=\"/status2=1\"\"><button>LED2 On </button></a>";
      cmd += "<a href=\"/status2=0\"\"><button>LED2 Off </button></a><br />";
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}
void led1off() {

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      cmd +=("Device1  : OFF");
      digitalWrite(output1, HIGH); 
      device1 = false;
      
      if(device2){
        cmd +=("<br/>Device2  : ON");
        digitalWrite(output2, LOW); 
        device2 = true;
      }
      else{
        cmd +=("<br/>Device2  : OFF");
        digitalWrite(output2, HIGH); 
        device2 = false;
      }
      cmd += "<br/><a href=\"/status1=1\"\"><button>LED1 On </button></a>";
      cmd += "<a href=\"/status1=0\"\"><button>LED1 Off </button></a><br />";
      cmd += "<a href=\"/status2=1\"\"><button>LED2 On </button></a>";
      cmd += "<a href=\"/status2=0\"\"><button>LED2 Off </button></a><br />";
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}

void led2on() {

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      digitalWrite(output2, LOW); 
      device2 = true;
      
      if(device1){
        cmd +=("Device1  : ON");
        digitalWrite(output1, LOW); 
        device1 = true;
      }
      else{
        cmd +=("Device1  : OFF");
        digitalWrite(output1, HIGH); 
        device1 = false;
      }
      
      cmd +=("<br/>Device2  : ON");
      cmd += "<br/><a href=\"/status1=1\"\"><button>LED1 On </button></a>";
      cmd += "<a href=\"/status1=0\"\"><button>LED1 Off </button></a><br />";
      cmd += "<a href=\"/status2=1\"\"><button>LED2 On </button></a>";
      cmd += "<a href=\"/status2=0\"\"><button>LED2 Off </button></a><br />";
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}
void led2off() {

  String cmd;     
      cmd += "<!DOCTYPE HTML>\r\n";
      cmd += "<html>\r\n";
      cmd += "<head>";
      cmd += "<meta http-equiv='refresh' content='5'/>";
      cmd += "</head>";
      digitalWrite(output2, HIGH); 
      device2 = false;
      
      if(device1){
        cmd +=("Device1  : ON");
        digitalWrite(output1, LOW); 
        device1 = true;
      }
      else{
        cmd +=("Device1  : OFF");
        digitalWrite(output1, HIGH); 
        device1 = false;
      }
      
      cmd +=("<br/>Device2  : OFF");
      cmd += "<br/><a href=\"/status1=1\"\"><button>LED1 On </button></a>";
      cmd += "<a href=\"/status1=0\"\"><button>LED1 Off </button></a><br />";
      cmd += "<a href=\"/status2=1\"\"><button>LED2 On </button></a>";
      cmd += "<a href=\"/status2=0\"\"><button>LED2 Off </button></a><br />";
      cmd += "<html>\r\n";
      server.send(200, "text/html", cmd);
}

void setup(void){
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);

  digitalWrite(output1, HIGH); 
  digitalWrite(output2, HIGH);
   
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/status1=1", led1on);
    
  server.on("/status1=0", led1off);

  server.on("/status2=1", led2on);

  server.on("/status2=0", led2off);


  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
