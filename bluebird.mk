$(call inherit-product, vendor/gapps/x86_64/x86_64-vendor.mk)
$(call inherit-product, $(LOCAL_PATH)/../redroid/redroid_x86_64_only.mk)
PRODUCT_NAME := bluebird_x86_64_only
PRODUCT_DEVICE := bluebird_x86_64_only
PRODUCT_BRAND := blulebird
PRODUCT_MODEL := bluebird_x86_64_only
PRODUCT_SYSTEM_PROPERTIES += ro.bluebird=1
PRODUCT_PACKAGES += vnc_import
PRODUCT_PACKAGES += bpf_test
PRODUCT_PACKAGES += ecapture
PRODUCT_PACKAGES_OVERLAYS := $(LOCAL_PATH)/overlay
TARGET_PRODUCT_PROP := $(LOCAL_PATH)/product.prop

