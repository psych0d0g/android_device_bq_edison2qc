CyanogenMod device configuration for the bq Edison 2 Quad Core.

How to Build
---------------

Initialise from CyanogenMod:

    repo init -u git://github.com/CyanogenMod/android.git -b cm-11.0

Use the following local manifest:

    <?xml version="1.0" encoding="UTF-8"?>
    <manifest>
      <!-- bq-rk projects-->
      <project name="bq-rk3x/android_device_bq_rockchip-common" path="device/bq/rockchip-common" revision="cm-11.0" />
      <project name="bq-rk3x/android_device_bq_edison2qc" path="device/bq/edison2qc" revision="cm-11.0" />

      <project name="bq-rk3x/android_kernel_bq_rk3188" path="kernel/bq/edison2qc" revision="cm-11.0" />

      <project name="bq-rk3x/proprietary_vendor_bq" path="vendor/bq" revision="cm-11.0" />

      <!-- CyanogenMod projects with additional changes -->
      <remove-project name="CyanogenMod/android_frameworks_av" />
      <remove-project name="CyanogenMod/android_frameworks_native" />
      <project name="bq-rk3x/android_frameworks_av" path="frameworks/av" revision="cm-11.0" />
      <project name="bq-rk3x/android_frameworks_native" path="frameworks/native" revision="cm-11.0" />
    </manifest>

Sync and build:

    repo sync -j4
    . build/envsetup.sh
    brunch edison2qc
