Purpose: read a 'bootargs_input.txt' to generat 'bootargs.bin' and 'Partition_table.xml'.
Command: mkbootargs bootargssize [SPI flash size] [Nand flash size]
         bootargssize: size in KB. usually, bootargssize is set to the bootargs partition size. default:512.
         SPI flash size: size in MB. usually, SPI flash size-Total partition size is set to 'other' partition of SPI flash . default:0MB.
         Nand flash size: size in MB. usually, Nand flash size-Total partition size is set to 'other' partition of Nand flash  . default:256MB.
         mkbootargs will read a 'bootargs_input.txt' and generat 'bootargs.bin' and 'Partition_table.xml'.
         Example:./makebootargs 512 0 256 
