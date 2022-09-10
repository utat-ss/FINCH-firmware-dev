# Firmware Testing and Development

This is the main repo for the development of component drivers, software, and other integrations with the MCUs. Final firmware is committed to the [firmware-core](https://github.com/spacesys-finch/firmware-core) repo.

The `main` branch is used to store templates for each of the devkits (currently the [NUCLEO-H743ZI2](NUCLEO-H743ZI2-template/) and the [NUCLEO-G431RB](NUCLEO-G431RB-template/)), and then development is done in individual branches. This helps manage the size of the cloned repo on local machines.

## How to use this repo

1. Clone the repo onto your local machine (click the green Clone button in the top right corner, copy the URL, and run `git clone [URL]` in your terminal to clone into a folder).
2. Move into the folder with `cd firmware-dev`.
3. Create a new branch, and name it based on your current task. For example, if you're working on a driver for a reaction wheel called HT-323: `git checkout -n HT323-reaction-wheel-driver`
4. Open STM32CubeIDE. Click "File", then "Open Projects from File System...". Click "Directory...", and select the `firmware-dev` folder.
5. Leave the template for the MCUs that you want to target checked. For example, reaction wheels are developed for the G4-series MCU, so only leave `NUCLEO-G431RB-template` checked. Then click Finish to open the repo.
6. Right click on the project in the Project Explorer on the left (the icon says "IDE"), and select Rename. Give your project a name (ex. `HT232-driver`), leave the "Update references" box checked, and click Ok.
7. [OPTIONAL] Delete the template for the other MCU.
8. Finally, commit the changes and push the branch to GitHub. In the terminal, from the `firmware-dev` folder:

   ```bash
   git add .
   git commit -m "[HT232-driver] Initial commit"
   git push -u origin HT232-reaction-wheel-driver
   ```

9. Once the driver is complete, have it merged into the [firmware-core](https://github.com/spacesys-finch/firmware-core) branch for that MCU.
