# Firmware Testing and Development

This is the main repo for the development of component drivers, software, and other integrations with the MCUs. Final firmware is committed to the [firmware-core](https://github.com/spacesys-finch/firmware-core) repo.

The `main` branch is used to store templates for each of the devkits (currently the [NUCLEO-H743ZI2](NUCLEO-H743ZI2-template/) and the [NUCLEO-G431RB](NUCLEO-G431RB-template/)), and then development is done in individual branches. This helps manage the size of the cloned repo on local machines.

## How to use this repo

1. Clone the repo onto your local machine; click the green "Clone" button in the top right corner, copy the URL, and run the following in your terminal to clone into a folder and enter it:

    ```bash
    git clone [URL]
    cd firmware
    ```

2. Create a new branch, and name it based on your current task. For example, if you're working on a driver for a reaction wheel called HT323:

    ```bash
    git checkout -b HT323-reaction-wheel-driver
    ```

3. Open STM32CubeIDE. Click "File", then "Open Projects from File System...". Click "Directory...", and select the `firmware-dev` folder.
4. Leave the template for the MCUs that you want to target checked. For example, reaction wheels are developed for the G4-series MCU using the Nucleo board, so only leave `NUCLEO-G431RB-template` checked. Then click Finish to open the repo.
5. Right click on the project in the Project Explorer on the left (the icon says "IDE"), and select Rename. Give your project a name (ex. `HT323-driver`), leave the "Update references" box checked, and click Ok.
6. [OPTIONAL] Delete the folder with the template for the other MCUs.
7. Finally, commit the changes and push the branch to GitHub. In the terminal, from the `firmware-dev` folder:

    ```bash
    git add .
    git commit -m "[HT323-driver] Initial commit"
    git push -u origin HT323-reaction-wheel-driver
    ```

8. Start developing your project. If the code is intended to be loaded onto the satellite, have it merged into the [firmware-core](https://github.com/spacesys-finch/firmware-core) branch for that MCU.
