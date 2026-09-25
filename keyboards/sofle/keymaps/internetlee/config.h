// Copyright 2024 Lee Haugen (@internetlee)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Encoders read inverted on this build; correct both directions.
#define ENCODER_DIRECTION_FLIP

// Tri-layer: hold Lower (1) + Raise (2) together -> Adjust (3)
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

// Sync state to the slave half so its OLED HUD is accurate.
#define SPLIT_LAYER_STATE_ENABLE                        // layer name on both halves
#define SPLIT_LED_STATE_ENABLE                          // caps-lock carets on both halves
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_SYNC_CAPS_WORD // caps-word carets on both halves
