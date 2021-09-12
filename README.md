# Hebert

## Hardware
* [DF Robot Turtle 2WD Platform](https://www.dfrobot.com/product-65.html)
    * $34.90 (before shipping)
* [DF Robot Romeo BLE Controller](https://www.dfrobot.com/product-1176.html)
    * $39.50 (before shipping)

Total after shipping to Oklahoma was right at $99.

## Code
* [Arduino IDE](https://www.arduino.cc/en/software)

Install the Arduino IDE and open up the `hebert-arduino/hebert-arduino.ino`
project.

You can ignore the tabs for `GoBLE.cpp`, `GoBLE.h`, and `QueueArray.h` as that
is just code provided by DF Robot for interacting with their GoBLE application.

## Tools
* Soldering Iron, something cheap and simple like [this](https://www.amazon.com/dp/B08N44XR5V)
  is sufficient.
    * That kit comes with solder and everything you need, but if you get a different
      one make sure to pick up some solder as well, it's a very big and simple
      connection that needs to be soldered so basically anything you can buy
      will work.
* Flush Cutters, I recommend [these](https://www.amazon.com/dp/B00FZPDG1K), they're
  small, cheap, and relatively well made.
* Small Screwdriver Set, anything will work, you will just need a #2 sized philips
  head for most of the screws in the kit, but there are 4 tiny philips screws
  so you will need a philips screwdriver that is slightly bigger than the average
  glasses screwdriver for those.
* Pliers, same as the screwdrivers, almost anything will work, there are just
  a couple of nuts you need to hold still while tightening a few of the screws
  and a second pair is very useful for attaching the little PCB standoffs at the
  end.

## Assembly
1. You can follow the instructions that come with the Turtle platform, though
   they have a few screws incorrectly labeled on in the directions, but all the
   pictures seem to be correct!
    * There will still be a few steps that come after everything the instruction
      manual goes over.
2. To wire up the switch and barrel jack connector you will need the soldering
   iron as mentioned up in tools. I can send pictures and help with that part
   at the end.
3. Then you'll want to attach the Romeo BLE Controller to the top of the Turtle
   using the standoffs, it's easiest to use screws to attach the standoffs to
   the holes in the controller and then put them into top of the Turtle.
    * I can help and send pictures of how that all goes together, since there
      are a ton of standoff holes that you can use for different controller boards.
4. Next you'd wire up the power cables and the two wheel motors to the controller.
    * This bit is entirely custom to this project, so I can send pictures of which
      connectors go where at this stage.
5. Finally you hook the board up to your computer and use the Arduino IDE to
   program the controller.
    * Wait to install batteries until after you do this just in case it tries
      to drive off and yank the USB cable outta your computer lol.

## Driving
Finally, go and get the GoBLE app on iOS or look [here](https://baixarapk.gratis/en/app/950937437/goble-bluetooth-4-0-controller)
for info about the Android version.

If the turtle is on, you should be able to just open the app and it'll make a
sound when it connects and the little icon in the top center will change color.

If it does not connect you may need to just press the tiny button on the controller
board that has the text `BOOT` next to it.

Once connected just use the joystick to go forward/backward/turn left/right.
It's very simple and doesn't have any speed control, but we can add that later!
