#pragma once

#include "sfse/GameTypes.h"
#include "sfse_common/Utilities.h"

class Actor;
struct BGSHotloadCompletedEvent {};

// BSTGlobalEvent

struct SnapTemplateUtils
{
    struct SnapReplaceEvent {};
};
struct ImageFixtureEvent_RequestImage {};
struct ImageFixtureEvent_UnregisterImage {};
struct Spaceship
{
    struct TakeOffEvent {};
    struct PlayerMovementOutputEvent {};
    struct GravJumpEvent {};
    struct LandedSetEvent {};
    struct BoughtEvent {};
    struct ContrabandScanWarningEvent {};
    struct DockEvent {};
    struct DynamicNavmeshCompleted {};
    struct FarTravelEvent {};
    struct LandingEvent {};
    struct PlanetScanEvent {};
    struct RampDownEvent {};
    struct RefueledEvent {};
    struct RegisteredEvent {};
    struct ShieldEvent {};
    struct ShipAddedEvent {};
    struct ShipCollisionEvent {};
    struct ShipCustomizedEvent {};
    struct SoldEvent {};
    struct SystemDamagedEvent {};
    struct SystemPowerAllocationEvent {};
    struct SystemPowerChangeEvent {};
    struct SystemRepairedBIEvent {};
    struct SystemRepairedEvent {};
    struct TakeDamagEvent {};
};
struct HUDActivityIncreaseEvent {};
struct AnimationDataCleanupEvent {};
struct AnimationDataSetupEvent {};
struct EndLoadGameEvent {};
struct StartLoadGameEvent {};
struct ShipEditor_SystemSelected {};
struct ShipEditor_PreviewUpgrade {};
struct ShipEditor_SelectedUpgrade {};
struct RuntimeComponentDBFactory
{
    struct ReferenceAttach {};
    struct ReferenceDetach {};
    struct ReferenceCleared3d {};
    struct ReferenceDestroy {};
    struct ReferenceInit {};
    struct ReferenceRecycle {};
    struct ReferenceSet3d {};
    struct Release3DRelatedData {};
};
struct WeaponGroupAssignmentMenu_ChangeWeaponAssignment {};
struct WeaponGroupAssignmentMenu_OnHintButtonActivated {};
struct ShipEditor_OnExitConfirmCancel {};
struct ShipEditor_OnExitConfirmExit {};
struct ShipEditor_OnExitConfirmSaveAndExit {};
struct ShipEditor_OnFlightCheckTabChanged {};
struct ShipEditor_OnWeaponGroupChanged {};
struct ShipEditor_OnRenameEndEditText {};
struct ShipEditor_OnRenameInputCancelled {};
struct ShipEditor_ChangeModuleCategory {};
struct ShipEditor_PreviewShipPart {};
struct ShipEditor_SelectedShipPart {};
struct ShipEditor_OnColorPickerControlChanged {};
struct ShipEditor_OnColorPickerTabChanged {};
struct ShipEditor_OnColorSliderMouseInput {};
struct ShipEditor_OnRecentColorSwatchClicked {};
struct ShipBuilder_CloseAllMenus {};
struct ShipEditor_OnHintButtonActivated {};
struct ShipEditor_RemoveAll3D {};
struct ReferenceQueuedEvent {};
struct LoadScreenEndEvent {};
struct LoadScreenStartEvent {};
struct CellAttachDetachEvent {};
struct PickRefStateChangedEvent {};
struct ActivityTrackerActivityStartedEvent {};
struct BSWorldOriginShiftEvent {};
struct BGSPlanet
{
    struct PlayerKnowledgeFlagSetEvent {};
};
struct StarMap
{
    struct PlanetTraitKnownEvent {};
};
struct ResetHistoryDataEvent {};
struct TESQuestRewardEvent {};
struct HUDWeaponWorldFOVMultChangedEvent {};
struct BGSSceneActionPlayerDialogue
{
    struct ActionEndEvent {};
    struct ActionStartEvent {};
};

struct AutoLoadDoorRolloverEvent {};
struct ClearQuickContainerEvent {};
struct ReferenceCellLoadedTemps {};
struct Workshop
{
    struct CargoLinkAddedEvent {};
    struct CargoLinkTargetChangedEvent {};
    struct EnterOutpostBeaconModeEvent {};
    struct ItemGrabbedEvent {};
    struct ItemMovedEvent {};
    struct ItemPlacedEvent {};
    struct ItemProducedEvent {};
    struct ItemRemovedEvent {};
    struct ItemRepairedEvent {};
    struct ItemScrappedEvent {};
    struct OutpostNameChangedEvent {};
    struct OutpostPlacedEvent {};
    struct PlacementStatusEvent {};
    struct PowerOffEvent {};
    struct PowerOnEvent {};
    struct SnapBehaviorCycledEvent {};
    struct WorkshopFlyCameraEvent {};
    struct WorkshopItemPlacedEvent {};
    struct WorkshopModeEvent {};
    struct WorkshopOutputLinkEvent {};
    struct WorkshopStatsChangedEvent {};
    struct WorkshopUpdateStatsEvent {};
};

struct PickRefUpdateEvent {};

struct ShipCameraStateToggled {};
struct PlayerControls
{
    struct PlayerJumpPressEvent {};
    struct PlayerJumpReleaseEvent {};
    struct PlayerZeroGSprintJustPressedEvent {};
    struct PlayerZeroGSprintReleasedEvent {};
    struct PlayerIronSightsEndEvent {};
    struct PlayerIronSightsStartEvent {};
};
struct PlayerSneakingChangeEvent {};
struct SaveLoadEvent {};
struct SpaceshipWeaponBinding
{
    struct SpaceshipWeaponBindingChangedEvent {};
};
struct BoundaryMenu_FastTravel {};
struct BoundaryMenu_ShowMap {};
struct PhotoGallery_DeletePhoto {};
struct PowersMenu_ActivateEssence {};
struct PowersMenu_EquipPower {};
struct PowersMenu_FavoritePower {};
struct ContainerMenuClosed
{
    struct Event {};
};
struct HangarShipSelection_ChangeSystemDisplay {};
struct HangarShipSelection_RepairShip {};
struct HangarShipSelection_UpgradeSystem {};
struct ShipCrewMenu_Close {};
struct BinkMovieStoppedPlayingEvent {};
struct WorkshopColorMode_ApplyColors {};
struct WorkshopColorMode_SelectedTab {};
struct WorkshopColorMode_SliderChanged {};
struct WorkshopColorMode_SwatchChanged {};
struct HUDCrewBuffMessageEvent {};
struct CraftingMenu_SessionSummaryEvent {};
struct CraftingMenu_CraftItem {};
struct CraftingMenu_ExitBench {};
struct CraftingMenu_InstallMod {};
struct CraftingMenu_RenameItem {};
struct CraftingMenu_RevertedModdedItem {};
struct CraftingMenu_SelectedMod {};
struct CraftingMenu_SelectedModSlot {};
struct CraftingMenu_SelectedModdableItem {};
struct CraftingMenu_SelectedRecipe {};
struct CraftingMenu_SetInspectControls {};
struct CraftingMenu_ToggleTracking {};
struct CraftingMenu_ViewingModdableItem {};
struct ContainerMenu_CloseMenu {};
struct InventoryMenu_Change3DView {};
struct InventoryMenu_PaperDollTryOn {};
struct InventoryMenu_ResetPaperDollInv {};
struct UpdateActivateListenerEvent {};
struct StartOutpostFromListenerEvent {};
struct HUDModeEvent {};
struct OpenContainerMenuEventData {};
struct OpenContainerMenuFromListenerEvent {};
struct HUDRolloverActivationButtonEvent {};
struct HUDRolloverActivationQCItemPressEvent {};
struct Inventory_SetSort {};
struct ShowingQuestMarketTextEvent {};
struct TargetHitEvent {};
struct PlayerCrosshairModeEvent {};
struct ClearHUDMessagesEvent {};
struct ShowHUDMessageEvent {};
struct PlayerDetectionLevelChangeEvent {};
struct ShowCustomWatchAlert {};
struct PlayerUpdateEvent {};
struct InventoryMenu_ToggleHelmet {};
struct InventoryMenu_ToggleSuit {};
struct ControlsRemappedEvent {};
struct SettingsPanel_CheckBoxChanged {};
struct SettingsPanel_ClearBinding {};
struct SettingsPanel_OpenCategory {};
struct SettingsPanel_OpenSettings {};
struct SettingsPanel_RemapConfirmed {};
struct SettingsPanel_RemapMode {};
struct SettingsPanel_ResetToDefaults {};
struct SettingsPanel_SaveControls {};
struct SettingsPanel_SaveSettings {};
struct SettingsPanel_SliderChanged {};
struct SettingsPanel_StepperChanged {};
struct SettingsPanel_ValidateControls {};
struct ShipCrewMenu_OpenAssignMenu {};
struct ShipCrewMenu_SetSort {};
struct ShowLongShipBootup {};
struct ShipHudQuickContainer_TransferMenu {};
struct ShipHud_Activate {};
struct ShipHud_BodyViewMarkerDimensions {};
struct ShipHud_ChangeComponentSelection {};
struct ShipHud_CloseMenu {};
struct ShipHud_Deselect {};
struct ShipHud_FarTravel {};
struct ShipHud_HailAccepted {};
struct ShipHud_HailCancelled {};
struct ShipHud_JumpToQuestMarker {};
struct ShipHud_Land {};
struct ShipHud_LandingMarkerMap {};
struct ShipHud_Map {};
struct ShipHud_OnMonocleToggle {};
struct ShipHud_OpenPhotoMode {};
struct ShipHud_Repair {};
struct ShipHud_SetTargetMode {};
struct ShipHud_Target {};
struct ShipHud_TargetShipSystem {};
struct ShipHud_UntargetShipSystem {};
struct ShipHud_UpdateComponentPower {};
struct DialogueMenu_CompleteExit {};
struct BGSScannerGuideEffectStatusUpdateEvent {};
struct GlobalFunc_CloseAllMenus {};
struct GlobalFunc_CloseMenu {};
struct GlobalFunc_PlayMenuSound {};
struct GlobalFunc_StartGameRender {};
struct GlobalFunc_UserEvent {};
struct ExperienceMeterDisplayData {};
struct LevelUp_AnimFinished {};
struct LevelUp_OnWidgetShown {};
struct LevelUp_OpenDataMenu {};
struct LevelUp_ShowSkills {};
struct LocationTextWidget_FinishedQueue {};
struct DisplayFatigueWarningEvent {};
struct SaveLoadMessageStringEvent {};
struct HUDNotificationEvent {};
struct HUDNotification_MissionActiveWidgetUpdate {};
struct HUDNotification_OpenDataMenu {};
struct HUDNotification_OpenMissionMenu {};
struct HUDNotification_SetMissionActive {};
struct PlayerSetWeaponStateEvent {};
struct BarterMenu_BuyItem {};
struct BarterMenu_CloseMenu {};
struct BarterMenu_HideModel {};
struct BarterMenu_LoadModel {};
struct BarterMenu_SellItem {};
struct BarterMenu_SetMouseOverModel {};
struct BarterMenu_ShowFailureMessage {};
struct BarterMenu_ViewedItem {};
struct MissionMenu_ClearState {};
struct MissionMenu_PlotToLocation {};
struct MissionMenu_RejectQuest {};
struct MissionMenu_SaveCategoryIndex {};
struct MissionMenu_SaveOpenedId {};
struct MissionMenu_ShowItemLocation {};
struct MissionMenu_ToggleTrackingQuest {};
struct DataSlateButtons_acceptClicked {};
struct DataSlateButtons_cancelClicked {};
struct DataSlateMenu_playSFX {};
struct DataSlateMenu_toggleAudio {};
struct InventoryMenu_DropItem {};
struct InventoryMenu_HideModel {};
struct InventoryMenu_LoadModel {};
struct InventoryMenu_OnEnterCategory {};
struct InventoryMenu_OpenCargoHold {};
struct InventoryMenu_SelectItem {};
struct InventoryMenu_SetMouseOverModel {};
struct InventoryMenu_ToggleFavorite {};
struct MissionBoard_MissionEntryChanged {};
struct MissionBoard_MissionEntryPressed {};
struct MonocleMenu_Bioscan {};
struct MonocleMenu_FastTravel {};
struct MonocleMenu_Harvest {};
struct MonocleMenu_Initialize {};
struct MonocleMenu_Outpost {};
struct MonocleMenu_PhotoMode {};
struct MonocleMenu_Shutdown {};
struct MonocleMenu_SocialSpell {};
struct MonocleMenu_StartContainerView {};
struct MonocleMenu_StopContainerView {};
struct MonocleMenu_SurfaceMap {};
struct MonocleMenu_UseListScrollControls {};
struct MonocleMenu_ZoomIn {};
struct MonocleMenu_ZoomOut {};
struct PhotoMode_InitializeCategory {};
struct PhotoMode_ResetToDefaults {};
struct PhotoMode_SliderChanged {};
struct PhotoMode_StepperChanged {};
struct PhotoMode_TakeSnapshot {};
struct PhotoMode_ToggleHelmet {};
struct PhotoMode_ToggleUI {};
struct PickpocketMenu_OnItemSelect {};
struct ResearchMenu_AddMaterial {};
struct ResearchMenu_CategorySelected {};
struct ResearchMenu_ExitMenu {};
struct ResearchMenu_HideModel {};
struct ResearchMenu_PreviewProject {};
struct ResearchMenu_ProjectViewed {};
struct ResearchMenu_SetInspectControls {};
struct ResearchMenu_ToggleTrackingProject {};
struct UnlockedTerminalElementEvent {};
struct SecurityMenu_BackOutKey {};
struct SecurityMenu_CloseMenu {};
struct SecurityMenu_ConfirmExit {};
struct SecurityMenu_EliminateUnusedKeys {};
struct SecurityMenu_GetRingHint {};
struct SecurityMenu_SelectNewKey {};
struct SecurityMenu_TryUseKey {};
struct ShipCrewAssignMenu_Assign {};
struct ShipCrewAssignMenu_Unassign {};
struct ShipCrewMenu_ViewedItem {};
struct Refuel_Accept {};
struct Refuel_Cancel {};
struct SkillsMenu_Accept {};
struct SkillsMenu_AddPatch {};
struct SkillsMenu_Cancel {};
struct SkillsMenu_ChangeCursorVisibility {};
struct SkillsMenu_SaveLastCategory {};
struct BSChargenAPI
{
    struct BIDataUtils
    {
        struct MenuClosedEvent {};
        struct PresetNPCChangedEvent {};
    };
};
struct CharGen_BrowChange {};
struct CharGen_BrowColorChange {};
struct CharGen_CancelTextEntry {};
struct CharGen_CloseMenu {};
struct CharGen_CyclePronoun {};
struct CharGen_DirtScarsEtcChange {};
struct CharGen_EndBodyChange {};
struct CharGen_EndTextEntry {};
struct CharGen_EyeColorChange {};
struct CharGen_FacialHairChange {};
struct CharGen_FacialHairColorChange {};
struct CharGen_HairChange {};
struct CharGen_HairColorChange {};
struct CharGen_HeadpartPlusSelectorChange {};
struct CharGen_HeadpartPresetChange {};
struct CharGen_JewelryChange {};
struct CharGen_JewelryColorChange {};
struct CharGen_MakeupChange {};
struct CharGen_MarkingsChange {};
struct CharGen_PostBlendColorOptionChange {};
struct CharGen_PostBlendFaceChange {};
struct CharGen_PostBlendIntensityChange {};
struct CharGen_PresetChange {};
struct CharGen_RollOffLocomotion {};
struct CharGen_RollOnLocomotion {};
struct CharGen_RotatePaperdoll {};
struct CharGen_SetAdditionalSlider {};
struct CharGen_SetBackground {};
struct CharGen_SetBlockInputUnderPopup {};
struct CharGen_SetBodyValues {};
struct CharGen_SetCameraPosition {};
struct CharGen_SetPronoun {};
struct CharGen_SetSex {};
struct CharGen_SetSlider {};
struct CharGen_SetTrait {};
struct CharGen_ShowChooseBackgroundMessage {};
struct CharGen_ShowPlayerRenameMessage {};
struct CharGen_SkintoneChange {};
struct CharGen_StartBodyChange {};
struct CharGen_StartTextEntry {};
struct CharGen_SwitchBodyType {};
struct CharGen_SwitchLocomotion {};
struct CharGen_TeethChange {};
struct CharGen_TeethRollOff {};
struct CharGen_TeethRollOn {};
struct CharGen_ToggleMarking {};
struct CharGen_TogglePreviewHabSuit {};
struct UIMenuChargenMenuDisablePaperdoll {};
struct DataMenu_CloseMenu {};
struct DataMenu_ClosedForSubMenu {};
struct DataMenu_Missions {};
struct DataMenu_PlotToLocation {};
struct DataMenu_Reopened {};
struct DataMenu_SelectedAttributesMenu {};
struct DataMenu_SelectedInventoryMenu {};
struct DataMenu_SelectedMapMenu {};
struct DataMenu_SelectedPowersMenu {};
struct DataMenu_SelectedShipMenu {};
struct DataMenu_SelectedStatusMenu {};
struct DataMenu_SetMenuForQuickEntry {};
struct DataMenu_SetPaperDollActive {};
struct PauseMenu_ActionCanceled {};
struct PauseMenu_ConfirmAction {};
struct PauseMenu_ConfirmLoad {};
struct PauseMenu_ConfirmSave {};
struct PauseMenu_DeleteSave {};
struct PauseMenu_QuitToDesktop {};
struct PauseMenu_SetCharacter {};
struct PauseMenu_StartAction {};
struct PauseMenu_StartLoad {};
struct PauseMenu_UploadSave {};
struct PlayBink_CloseMenu {};
struct Reticle_OnLongAnimFinished {};
struct ShipHudQuickContainer_TransferItem {};
struct ShipHud_AbortJump {};
struct ShipHud_DockRequested {};
struct ShipHud_HailShip {};
struct ShipHud_UpdateTargetPanelRect {};
struct TakeoffMenu_CloseMenu {};
struct TakeoffMenu_ExitShip {};
struct TakeoffMenu_Launch {};
struct StarMapMenu_LandingInputInProgress {};
struct StarMapMenu_MarkerGroupContainerVisibilityChanged {};
struct StarMapMenu_MarkerGroupEntryClicked {};
struct StarMapMenu_MarkerGroupEntryHoverChanged {};
struct StarMapMenu_ScanPlanet {};
struct StarMapMenu_SelectedLandingSite {};
struct StarMapMenu_SelectedLandingSiteFailed {};
struct StarMapMenu_ShowRealCursor {};
struct StarMapMenu_QuickSelectChange {};
struct StarMapMenu_Galaxy_FocusSystem {};
struct StarMapMenu_OnGalaxyViewInitialized {};
struct StarMapMenu_ExecuteRoute {};
struct StarMapMenu_OnCancel {};
struct StarMapMenu_OnClearRoute {};
struct StarMapMenu_OnExitStarMap {};
struct StarMapMenu_OnHintButtonClicked {};
struct StarMapMenu_OnOutpostEntrySelected {};
struct StarMapMenu_ReadyToClose {};
struct SurfaceMapMenu_MarkerClicked {};
struct SurfaceMapMenu_TryPlaceCustomMarker {};
struct TerminalMenu_CancelEvent {};
struct Terminal_CloseAllViews {};
struct Terminal_CloseTopView {};
struct Terminal_CloseView {};
struct Terminal_MenuItemClick {};
struct TestMenu_DoAction {};
struct TestMenu_ExitMenu {};
struct TestMenu_ShowImages {};
struct TestMenu_ShowResources {};
struct TestMenu_TestAll {};
struct TextInputMenu_EndEditText {};
struct TextInputMenu_InputCanceled {};
struct TextInputMenu_StartEditText {};
struct CraftingMenu_Highlight3D {};
struct CraftingMenu_RevertHighlight {};
struct WorkshopBuilderMenu_ChangeBuildItem {};
struct WorkshopBuilderMenu_SelectedItem {};
struct WorkshopBuilderMenu_ToggleTracking {};
struct WorkshopMenu_AttemptBuild {};
struct WorkshopMenu_CancelAction {};
struct WorkshopMenu_ChangeVariant {};
struct WorkshopMenu_ConnectionEvent {};
struct WorkshopMenu_ExitMenu {};
struct WorkshopMenu_MessageCallback {};
struct WorkshopMenu_SelectedCategory {};
struct WorkshopMenu_SelectedGridObject {};
struct WorkshopMenu_ShowExtras {};
struct WorkshopMenu_SwitchMode {};
struct WorkshopMenu_ToggleDistance {};
struct WorkshopMenu_ToggleTracking {};
struct WorkshopMenu_ToggleView {};
struct WorkshopQuickMenu_ConfirmAction {};
struct WorkshopQuickMenu_ExitMenu {};
struct WorkshopTargetMenu_TargetHovered {};
struct WorkshopTargetMenu_TargetPicked {};
struct WorkshopActionButton_HoldFinished {};
struct WorkshopActionButton_HoldStopped {};
struct WorkshopShared_SetActionHandles {};
struct WorkshopShared_StartAction {};
struct ModelReferenceEffectEvents
{
    struct ReferenceEffectFinished {};
};
struct BGSAcousticSpaceListener
{
    struct StackChangedEvent {};
};
struct SpaceshipBIEvents
{
    struct ShipPowerAllocationBIEventSent {};
};
struct BGSActorDeathEvent {};
struct Research
{
    struct ResearchProgressEvent {};
};
struct PlayerAutoAimActorEvent {};
struct PlayerInCombatChangeEvent {};
struct BlurEvent {};
struct ContainerMenu_HideModel {};
struct ContainerMenu_Jettison {};
struct ContainerMenu_LoadModel {};
struct ContainerMenu_OpenRefuelMenu {};
struct ContainerMenu_SetMouseOverModel {};
struct ContainerMenu_TakeAll {};
struct ContainerMenu_ToggleEquip {};
struct ContainerMenu_TransferItem {};
struct DialogueMenu_OnDialogueSelect {};
struct DialogueMenu_OnListVisibilityChange {};
struct DialogueMenu_OnPersuasionAutoWin {};
struct DialogueMenu_OnScriptedDialogueSelect {};
struct DialogueMenu_RequestExit {};
struct DialogueMenu_RequestSkipDialogue {};
struct FaderMenuDisplayState {};
struct FavoritesMenu_AssignQuickkey {};
struct FavoritesMenu_UseQuickkey {};
struct LoadingMenu_RefreshText {};
struct MainMenu_ActionCanceled {};
struct MainMenu_ActionConfirmed {};
struct MainMenu_ConfirmLoad {};
struct MainMenu_DeleteSave {};
struct MainMenu_SetCharacter {};
struct MainMenu_StartAction {};
struct MainMenu_StartLoad {};
struct MainMenu_UploadSave {};
struct BGSAppPausedEvent {};
struct MessageBoxMenu_OnBackOut {};
struct MessageBoxMenu_OnButtonPress {};
struct MessageBoxMenu_OnScriptedButtonPress {};
struct SleepWaitMenu_InterruptRest {};
struct SleepWaitMenu_StartRest {};

struct ContextStackChangedEvent {};
struct UpdateSceneRectEvent {};
struct GameStalledEvent {};

// more

struct TESCellNavmeshGeneratedEvent {};
struct TESHitEvent {};
struct FirstThirdPersonSwitch
{
    struct Event {};
};
struct PerkChanged
{
    struct Event {};
};
struct TESHarvestEvent
{
    struct ItemHarvested {};
};
struct ActivityEvents
{
    struct ActivityCompletedEvent {};
};
struct ChallengeCompletedEvent
{
    struct Event {};
};
struct InventoryItemEvent
{
    struct Event {};
};
struct BooksRead
{
    struct Event {};
};
struct LocationExplored
{
    struct Event {};
};
struct LocationLinked
{
    struct Event {};
};
struct Activation
{
    struct Event {};
};
struct ActorCellChangeEvent {};
struct ActorHeadAttachedEvent {};
struct ActorValueEvents
{
    struct ActorValueChangedEvent {};
};
struct AliasChangeEvent {};
struct AnimationGraphDependentEvent {};
struct BGSAffinityEventEvent {};
struct BGSCellGridLoadEvent {};
struct BGSEventProcessedEvent {};
struct BGSHavokWorldCreatedEvent {};
struct BGSLocationLoadedEvent {};
struct BGSOnPlayerCompanionDismiss {};
struct BGSOnPlayerCompleteResearchEvent {};
struct BGSOnPlayerCraftItemEvent {};
struct BGSOnPlayerCreateRobotEvent {};
struct BGSOnPlayerEnterVertibirdEvent {};
struct BGSOnPlayerFallLongDistances {};
struct BGSOnPlayerFireWeaponEvent {};
struct BGSOnPlayerHealTeammateEvent {};
struct BGSOnPlayerLoiteringBeginEvent {};
struct BGSOnPlayerLoiteringEndEvent {};
struct BGSOnPlayerModArmorWeaponEvent {};
struct BGSOnPlayerModRobotEvent {};
struct BGSOnPlayerSwimmingEvent {};
struct BGSOnPlayerUseWorkBenchEvent {};
struct BGSOnSpeechChallengeAvailable {};
struct BGSRadiationDamageEvent {};
struct BuilderMenuSelectEvent {};
struct CrewAssignedEvent {};
struct CrewDismissedEvent {};
struct DestroyedEvent {};
struct HomeShipSetEvent {};
struct InstantReferenceInteractionEvent {};
struct ItemConsumedEvent {};
struct ItemSwappedEvent {};
struct LockPickedEvent {};
struct MapMarkerDiscoveredEvent {};
struct ObjectScannedEvent {};
struct PlayerAddItemEvent {};
struct PlayerArrestedEvent {};
struct PlayerAssaultActorEvent {};
struct PlayerBuyShipEvent {};
struct PlayerCrimeGoldEvent {};
struct PlayerFailedPlotRouteEvent {};
struct PlayerJailEvent {};
struct PlayerModifiedShipEvent {};
struct PlayerMurderActorEvent {};
struct PlayerPayFineEvent {};
struct PlayerPlanetSurveyCompleteEvent {};
struct PlayerPlanetSurveyProgressEvent {};
struct PlayerSellShipEvent {};
struct PlayerTrespassEvent {};
struct QuickContainerOpenedEvent {};
struct RefControlChangedEvent {};
struct ReferenceDestroyedEvent {};
struct SpeechChallengeCompletionEvent {};
struct TESActivateEvent {};
struct TESActiveEffectApplyFinishEvent {};
struct TESActiveEffectRemovedEvent {};
struct TESActorActivatedRefEvent {};
struct TESActorLocationChangeEvent {};
struct TESBookReadEvent {};
struct TESCellCriticalRefsAttachedEvent {};
struct TESCellFullyLoadedEvent {};
struct TESCellGravityChangeEvent {};
struct TESCellReadyToApplyDecalsEvent {};
struct TESCellReference3DAttachEvent {};
struct TESCellReferenceAttachDetachEvent {};
struct TESCombatEvent {};
struct TESCombatListEvent {};
struct TESCommandModeCompleteCommandEvent {};
struct TESCommandModeEnterEvent {};
struct TESCommandModeExitEvent {};
struct TESCommandModeGiveCommandEvent {};
struct TESConsciousnessEvent {};
struct TESContainerChangedEvent
{
    u32          sourceContainerFormID;              // 00
    u32          targetContainerFormID;                // 04
    u32          itemFormID;                            // 08
    u32          count;                                // 0C
    //...
};
struct TESDeathEvent {};
struct TESDeferredKillEvent {};
struct TESDestructionStageChangedEvent {};
struct TESEnterBleedoutEvent {};
struct TESEnterSneakingEvent {};
struct TESEquipEvent {};
struct TESEscortWaitStartEvent {};
struct TESEscortWaitStopEvent {};
struct TESExitBleedoutEvent {};
struct TESExitFurnitureEvent {};
struct TESFormDeleteEvent
{
    u32 formId; // 00
};
struct TESFormIDRemapEvent
{
    u32 oldID;  // 00
    u32 newID;  // 04
};
struct TESFurnitureEvent {};
struct TESGrabReleaseEvent {};
struct TESInitScriptEvent {};
struct TESLimbCrippleEvent {};
struct TESLoadGameEvent {};
struct TESLocationExploredEvent {};
struct TESLockChangedEvent {};
struct TESMagicEffectApplyEvent {};
struct TESMissionAcceptedEvent {};
struct TESObjectLoadedEvent {};
struct TESObjectREFRTranslationEvent {};
struct TESOnPCDialogueTargetEvent {};
struct TESOpenCloseEvent {};
struct TESPackageEvent {};
struct TESPerkEntryRunEvent {};
struct TESPickNewIdleEvent {};
struct TESPickpocketFailedEvent {};
struct TESPlayerActiveEffectEvent {};
struct TESPlayerFollowerWarpEvent {};
struct TESQuestInitEvent {};
struct TESQuestRejectedEvent {};
struct TESQuestStageEvent {};
struct TESQuestStageItemDoneEvent {};
struct TESQuestStartStopEvent {};
struct TESQuestTimerEvent {};
struct TESResetEvent {};
struct TESResolveNPCTemplatesEvent {};
struct TESSceneActionEvent {};
struct TESSceneEvent {};
struct TESScenePhaseEvent {};
struct TESSellEvent {};
struct TESSleepStartEvent {};
struct TESSleepStopEvent {};
struct TESSpellCastEvent {};
struct TESSpellCastFailureEvent {};
struct TESSwitchRaceCompleteEvent {};
struct TESTopicInfoEvent {};
struct TESTrackedStatsEvent {};
struct TESTrapHitEvent {};
struct TESTriggerEnterEvent {};
struct TESTriggerEvent {};
struct TESTriggerLeaveEvent {};
struct TESUniqueIDChangeEvent {};
struct TESWaitStartEvent {};
struct TESWaitStopEvent {};
struct TerminalMenuMenuItemRunEvent {};
struct TerminalMenuOnEnterEvent {};
struct WorkshopNPCTransferEvent {};
struct TESObjectREFRIsReadyForAttachEvent {};
struct DefaultObjectsReadyEvent
{
    struct Event {};
};
struct ObjectiveState
{
    struct Event {};
};
struct QuestStatus
{
    struct Event {};
};
struct RefillAliasEvent
{
    struct Event {};
};
struct TESQuestEvent
{
    struct Event {};
};
struct RolloverIsCrimeEvent
{
    struct Event {};
};
struct HideSubtitleEvent
{
    struct Event {};
};
struct ShowSubtitleEvent
{
    struct Event {};
};
struct MissionMenuStateEvent
{
    struct Event {};
};
struct ClearShipHudTarget
{
    struct Event {};
};
struct TryUpdateShipHudTarget
{
    struct Event {};
};
struct LocationTextEvent
{
    struct Event {};
};
struct TraitDiscoveryTextEvent
{
    struct Event {};
};
struct DaysPassed
{
    struct Event {};
};
struct HourPassed
{
    struct Event {};
};
struct ActorDamage
{
    struct Event {};
};
struct ActorItemEquipped
{
    struct Event {};
};
struct ActorKill
{
    struct Event {};
};
struct AssaultCrime
{
    struct Event {};
};
struct DisarmedEvent
{
    struct Event {};
};
struct FactionRankChange
{
    struct Event {};
};
struct GrandTheftHorse
{
    struct Event {};
};
struct MurderCrime
{
    struct Event {};
};
struct PiracyCrime
{
    struct Event {};
};
struct Bleedout
{
    struct Event {};
};
struct ContractedDisease
{
    struct Event {};
};
struct ReloadWeaponEvent
{
    struct Event {};
};
struct SpellsLearned
{
    struct Event {};
};
struct Bounty
{
    struct Event {};
};
struct ChestLooted
{
    struct Event {};
};
struct CriticalHitEvent
{
    struct Event {};
};
struct CustomMarkerUpdate
{
    struct Event {};
};
struct DaysJailed
{
    struct Event {};
};
struct EnteredUnity
{
    struct Event {};
};
struct FinePaid
{
    struct Event {};
};
struct ItemCrafted
{
    struct Event {};
};
struct ItemSteal
{
    struct Event {};
};
struct JailEscape
{
    struct Event {};
};
struct Jailing
{
    struct Event {};
};
struct LevelIncrease
{
    struct Event {};
};
struct LocationMarkerArrayUpdate
{
    struct Event {};
};
struct PlayerActiveEffectChanged
{
    struct Event {};
};
struct PlayerAmmoChanged
{
    struct Event {};
};
struct PlayerCharacterQuestEvent
{
    struct Event {};
};
struct PlayerDifficultySettingChanged
{
    struct Event {};
};
struct PlayerFastTravel
{
    struct Event {};
};
struct PlayerInDialogueChanged
{
    struct Event {};
};
struct PlayerLifeStateChanged
{
    struct Event {};
};
struct PlayerPickpocketSuccess
{
    struct Event {};
};
struct PoisonedWeapon
{
    struct Event {};
};
struct TerminalHacked
{
    struct Event {};
};
struct TravelMarkerStateChange
{
    struct Event {};
};
struct WeaponAttack
{
    struct Event {};
};
struct Trespass
{
    struct Event {};
};
struct VATSEvents
{
    struct ModeChange {};
};
struct VATSCommand {};
struct HoursPassed
{
    struct Event {};
};

// UI events

struct MenuOpenCloseEvent
{
    BSFixedString	MenuName;
    bool			bOpening;
};
struct MenuModeChangeEvent {};
struct MenuPauseChangeEvent {};
struct MenuPauseCounterChangeEvent {};
struct TutorialEvent {};
struct BSCursorTypeChange {};
struct BSCursorRotationChange {};
struct BIUIMenuVisiblePausedBeginEvent {};
struct BIUIMenuVisiblePausedEndEvent {};

// other events

struct RadioManager
{
    struct PipboyTransmitterDetectionEvent {};
};
struct XPChange
{
    struct Event
    {
        Actor* actor;
        void* unk08;
        float totalXP;
        float recievedXP;
        //...
    };
};
struct WeaponFiredEvent
{
    void* unk00;
    void* unk08;
    Actor* actor;
    //...
};
struct ActorEquipManagerEvent
{
    struct Event {};
    struct SpellEvent {};
};
struct AttachReference
{
    struct Event {};
};
//

namespace BSTEventDetail
{
    class SinkBase
    {
    public:
        virtual ~SinkBase() {};
    };

    class SourceBase
    {
    public:
        virtual ~SourceBase() {};
        DEFINE_MEMBER_FN_1(RegisterSink, void, 0x022C8E80, SinkBase* sink);
        DEFINE_MEMBER_FN_1(UnregisterSink, void, 0x022C9010, SinkBase* sink);
    };
}

enum class BSEventNotifyControl
{
    kContinue,
    kStop
};
using EventResult = BSEventNotifyControl;

template <typename T>
class BSTEventSource;

template <typename T>
class BSTEventSink : public BSTEventDetail::SinkBase
{
public:
    virtual ~BSTEventSink() { };
    virtual	EventResult	ProcessEvent(const T& arEvent, BSTEventSource<T>* eventSource) { return EventResult::kContinue; }; // pure
};

template<typename T>
class BSTEventSource : public BSTEventDetail::SourceBase
{
public:
    virtual ~BSTEventSource();

    BSTArray<BSTEventSink<T>> pSinksA;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
};

class BSTGlobalEvent
{
public:
    virtual ~BSTGlobalEvent();

    template <typename T>
    class EventSource : public BSTEventSource<T>
    {
    public:
        virtual ~EventSource();
        virtual EventResult ProcessEvent(const T& arEvent, BSTEventSource<T>* eventSource);
    };
};

template <class T>
class BSTValueEventSink :
    public BSTEventSink<T>  // 00
{
};

template <class T>
class BSTValueRequestEvent
{
};

template<typename EventT>
BSTEventSource<EventT>* GetEventSource() { };

#define DECLARE_EVENT_SOURCE(Event, address) \
template<> inline BSTEventSource<Event> * GetEventSource() \
{ \
    typedef BSTEventSource<Event> * (*_GetEventSource)(); \
    RelocAddr<_GetEventSource> GetEventSource(address); \
    return GetEventSource(); \
}

#define DECLARE_EVENT_SOURCE_EX(Event, address) \
template<> inline BSTEventSource<Event> * GetEventSource() \
{ \
RelocPtr<BSTEventSource<Event>> es(address); \
return es.getPtr(); \
}

DECLARE_EVENT_SOURCE(ActivityTrackerActivityStartedEvent, 0x00603060)
DECLARE_EVENT_SOURCE(ActorEquipManagerEvent::Event, 0x01898870)
DECLARE_EVENT_SOURCE(ActorEquipManagerEvent::SpellEvent, 0x01898870)
//DECLARE_EVENT_SOURCE(ActorInventoryEvent, 0x01984830)
DECLARE_EVENT_SOURCE(ActorValueEvents::ActorValueChangedEvent, 0x002B6660)
//DECLARE_EVENT_SOURCE(AddSaveLoadEntryEvent, 0x01453850)
DECLARE_EVENT_SOURCE(AliasChangeEvent, 0x00CFB160)
DECLARE_EVENT_SOURCE(AnimationDataCleanupEvent, 0x0030D8B0)
DECLARE_EVENT_SOURCE(AnimationDataSetupEvent, 0x0030D950)
DECLARE_EVENT_SOURCE(AutoLoadDoorRolloverEvent, 0x00A93760)
DECLARE_EVENT_SOURCE(BGSAcousticSpaceListener::StackChangedEvent, 0x0178E870)
DECLARE_EVENT_SOURCE(BGSActorDeathEvent, 0x013F85E0)
DECLARE_EVENT_SOURCE(BGSAppPausedEvent, 0x01ED47C0)
DECLARE_EVENT_SOURCE(BGSCellGridLoadEvent, 0x00578B80)
DECLARE_EVENT_SOURCE(BGSEventProcessedEvent, 0x00EECB70)
//DECLARE_EVENT_SOURCE(BGSKeyword::OnDestroyEvent, 0x00C88300)
DECLARE_EVENT_SOURCE(BGSOnPlayerCompleteResearchEvent, 0x01800F20)
DECLARE_EVENT_SOURCE(BGSPlanet::PlayerKnowledgeFlagSetEvent, 0x007BFE50)
DECLARE_EVENT_SOURCE(BGSScannerGuideEffectStatusUpdateEvent, 0x015A8F50)
DECLARE_EVENT_SOURCE(BGSSceneActionPlayerDialogue::ActionEndEvent, 0x009C2310)
DECLARE_EVENT_SOURCE(BGSSceneActionPlayerDialogue::ActionStartEvent, 0x009C23B0)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformBlocklistAvailableEvent, 0x02114360)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformCuratedListAvailableEvent, 0x0145FC20)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformInitializedEvent, 0x0145FB80)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformLinkedLoginEvent, 0x02108630)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformLoginEvent, 0x0145B940)
//DECLARE_EVENT_SOURCE(BSBethesdaPlatformShutdownEvent, 0x02BFA470)
DECLARE_EVENT_SOURCE(BSChargenAPI::BIDataUtils::MenuClosedEvent, 0x0165B4E0)
DECLARE_EVENT_SOURCE(BSChargenAPI::BIDataUtils::PresetNPCChangedEvent, 0x01659610)
//DECLARE_EVENT_SOURCE(BSEntitlementFoundEvent, 0x021086D0)
//DECLARE_EVENT_SOURCE(BSMaterial::MaterialsReloadedEvent, 0x02454BA0)
//DECLARE_EVENT_SOURCE(BSRedeemableFoundEvent, 0x01343180)
//DECLARE_EVENT_SOURCE(BSResource::Archive2::ClearRegistryEvent, 0x02760390)
//DECLARE_EVENT_SOURCE(BSResource::Archive2::RegisteredEvent, 0x02760390)
//DECLARE_EVENT_SOURCE(BSResource::Archive2::StreamOpenedEvent, 0x02760390)
//DECLARE_EVENT_SOURCE(BSResource::ArchiveRegisteredEvent, 0x02760390)
//DECLARE_EVENT_SOURCE(BSResource::NameFoundEvent, 0x0275BE40)
//DECLARE_EVENT_SOURCE(BSScript::StatsEvent, 0x027D0600)
//DECLARE_EVENT_SOURCE(BSTValueRequestEvent < FaderMenuDisplayState, 0x01E45A30)
//DECLARE_EVENT_SOURCE(BSTValueRequestEvent < PlayerAutoAimActorEvent, 0x019FCAC0)
//DECLARE_EVENT_SOURCE(BSTValueRequestEvent < PlayerCrosshairModeEvent, 0x0142AC00)
//DECLARE_EVENT_SOURCE(BSTValueRequestEvent < SaveLoadMessageStringEvent, 0x0155D990)
DECLARE_EVENT_SOURCE(BSWorldOriginShiftEvent, 0x00691580)
DECLARE_EVENT_SOURCE(BarterMenu_BuyItem, 0x015DA1D0)
DECLARE_EVENT_SOURCE(BarterMenu_CloseMenu, 0x015DA4F0)
DECLARE_EVENT_SOURCE(BarterMenu_HideModel, 0x015DA3B0)
DECLARE_EVENT_SOURCE(BarterMenu_LoadModel, 0x015DA450)
DECLARE_EVENT_SOURCE(BarterMenu_SellItem, 0x015DA130)
DECLARE_EVENT_SOURCE(BarterMenu_SetMouseOverModel, 0x015DA090)
DECLARE_EVENT_SOURCE(BarterMenu_ShowFailureMessage, 0x015DA310)
DECLARE_EVENT_SOURCE(BarterMenu_ViewedItem, 0x015DA270)
DECLARE_EVENT_SOURCE(BinkMovieStoppedPlayingEvent, 0x01402940)
DECLARE_EVENT_SOURCE(BlurEvent, 0x01E941A0)
DECLARE_EVENT_SOURCE(BoundaryMenu_FastTravel, 0x01387BE0)
DECLARE_EVENT_SOURCE(BoundaryMenu_ShowMap, 0x01387B40)
//DECLARE_EVENT_SOURCE(CameraCutEvent, 0x00F8AF90)
DECLARE_EVENT_SOURCE(CellAttachDetachEvent, 0x00586340)
DECLARE_EVENT_SOURCE(ChallengeCompletedEvent::Event, 0x00601E90)
DECLARE_EVENT_SOURCE(CharGen_BrowChange, 0x0165A860)
DECLARE_EVENT_SOURCE(CharGen_BrowColorChange, 0x0165A540)
DECLARE_EVENT_SOURCE(CharGen_CancelTextEntry, 0x0165AFE0)
DECLARE_EVENT_SOURCE(CharGen_CloseMenu, 0x0165B440)
DECLARE_EVENT_SOURCE(CharGen_CyclePronoun, 0x0165A400)
DECLARE_EVENT_SOURCE(CharGen_DirtScarsEtcChange, 0x0165AB80)
DECLARE_EVENT_SOURCE(CharGen_EndBodyChange, 0x01659BE0)
DECLARE_EVENT_SOURCE(CharGen_EndTextEntry, 0x0165B080)
DECLARE_EVENT_SOURCE(CharGen_EyeColorChange, 0x0165A900)
DECLARE_EVENT_SOURCE(CharGen_FacialHairChange, 0x0165A680)
DECLARE_EVENT_SOURCE(CharGen_FacialHairColorChange, 0x0165A5E0)
DECLARE_EVENT_SOURCE(CharGen_HairChange, 0x0165A7C0)
DECLARE_EVENT_SOURCE(CharGen_HairColorChange, 0x0165A720)
DECLARE_EVENT_SOURCE(CharGen_HeadpartPlusSelectorChange, 0x0165ACC0)
DECLARE_EVENT_SOURCE(CharGen_HeadpartPresetChange, 0x0165B300)
DECLARE_EVENT_SOURCE(CharGen_JewelryChange, 0x01659DC0)
DECLARE_EVENT_SOURCE(CharGen_JewelryColorChange, 0x01659D20)
DECLARE_EVENT_SOURCE(CharGen_MakeupChange, 0x01659820)
DECLARE_EVENT_SOURCE(CharGen_MarkingsChange, 0x01659780)
DECLARE_EVENT_SOURCE(CharGen_PostBlendColorOptionChange, 0x01659960)
DECLARE_EVENT_SOURCE(CharGen_PostBlendFaceChange, 0x01659A00)
DECLARE_EVENT_SOURCE(CharGen_PostBlendIntensityChange, 0x016598C0)
DECLARE_EVENT_SOURCE(CharGen_PresetChange, 0x0165B3A0)
DECLARE_EVENT_SOURCE(CharGen_RollOffLocomotion, 0x01659FA0)
DECLARE_EVENT_SOURCE(CharGen_RollOnLocomotion, 0x0165A040)
DECLARE_EVENT_SOURCE(CharGen_RotatePaperdoll, 0x0165A0E0)
DECLARE_EVENT_SOURCE(CharGen_SetAdditionalSlider, 0x01659B40)
DECLARE_EVENT_SOURCE(CharGen_SetBackground, 0x0165A9A0)
DECLARE_EVENT_SOURCE(CharGen_SetBlockInputUnderPopup, 0x01659AA0)
DECLARE_EVENT_SOURCE(CharGen_SetBodyValues, 0x0165AE00)
DECLARE_EVENT_SOURCE(CharGen_SetCameraPosition, 0x0165AD60)
DECLARE_EVENT_SOURCE(CharGen_SetPronoun, 0x0165A360)
DECLARE_EVENT_SOURCE(CharGen_SetSex, 0x0165B260)
DECLARE_EVENT_SOURCE(CharGen_SetSlider, 0x0165B1C0)
DECLARE_EVENT_SOURCE(CharGen_SetTrait, 0x0165AA40)
DECLARE_EVENT_SOURCE(CharGen_ShowChooseBackgroundMessage, 0x0165AEA0)
DECLARE_EVENT_SOURCE(CharGen_ShowPlayerRenameMessage, 0x0165AF40)
DECLARE_EVENT_SOURCE(CharGen_SkintoneChange, 0x0165AC20)
DECLARE_EVENT_SOURCE(CharGen_StartBodyChange, 0x01659C80)
DECLARE_EVENT_SOURCE(CharGen_StartTextEntry, 0x0165B120)
DECLARE_EVENT_SOURCE(CharGen_SwitchBodyType, 0x0165A180)
DECLARE_EVENT_SOURCE(CharGen_SwitchLocomotion, 0x0165A220)
DECLARE_EVENT_SOURCE(CharGen_TeethChange, 0x0165A4A0)
DECLARE_EVENT_SOURCE(CharGen_TeethRollOff, 0x01659E60)
DECLARE_EVENT_SOURCE(CharGen_TeethRollOn, 0x01659F00)
DECLARE_EVENT_SOURCE(CharGen_ToggleMarking, 0x0165AAE0)
DECLARE_EVENT_SOURCE(CharGen_TogglePreviewHabSuit, 0x0165A2C0)
//DECLARE_EVENT_SOURCE(CharacterBeginLevelUpEvent, 0x01750070)
//DECLARE_EVENT_SOURCE(CharacterFinishLevelUpEvent, 0x0147DCF0)
DECLARE_EVENT_SOURCE(ClearHUDMessagesEvent, 0x01491500)
DECLARE_EVENT_SOURCE(ClearQuickContainerEvent, 0x00A93800)
DECLARE_EVENT_SOURCE(ContainerMenuClosed::Event, 0x013F25C0)
DECLARE_EVENT_SOURCE(ContainerMenu_CloseMenu, 0x0145ACE0)
DECLARE_EVENT_SOURCE(ContainerMenu_HideModel, 0x01EB5DE0)
DECLARE_EVENT_SOURCE(ContainerMenu_Jettison, 0x01EB5CA0)
DECLARE_EVENT_SOURCE(ContainerMenu_LoadModel, 0x01EB5E80)
DECLARE_EVENT_SOURCE(ContainerMenu_OpenRefuelMenu, 0x01EB5D40)
DECLARE_EVENT_SOURCE(ContainerMenu_SetMouseOverModel, 0x01EB5C00)
DECLARE_EVENT_SOURCE(ContainerMenu_TakeAll, 0x01EB5F20)
DECLARE_EVENT_SOURCE(ContainerMenu_ToggleEquip, 0x01EB6060)
//DECLARE_EVENT_SOURCE(ContainerMenu_TransferAllResources, 0x01E3FA50)
DECLARE_EVENT_SOURCE(ContainerMenu_TransferItem, 0x01EB6100)
DECLARE_EVENT_SOURCE(ContextStackChangedEvent, 0x022F60D0)
DECLARE_EVENT_SOURCE(ControlsRemappedEvent, 0x01534360)
DECLARE_EVENT_SOURCE(CraftingMenu_CraftItem, 0x0144C4C0)
DECLARE_EVENT_SOURCE(CraftingMenu_ExitBench, 0x0144C740)
DECLARE_EVENT_SOURCE(CraftingMenu_Highlight3D, 0x017172D0)
DECLARE_EVENT_SOURCE(CraftingMenu_InstallMod, 0x0144C380)
DECLARE_EVENT_SOURCE(CraftingMenu_RenameItem, 0x0144BFC0)
DECLARE_EVENT_SOURCE(CraftingMenu_RevertHighlight, 0x01717230)
DECLARE_EVENT_SOURCE(CraftingMenu_RevertedModdedItem, 0x0144C060)
DECLARE_EVENT_SOURCE(CraftingMenu_SelectedMod, 0x0144C100)
DECLARE_EVENT_SOURCE(CraftingMenu_SelectedModSlot, 0x0144C1A0)
DECLARE_EVENT_SOURCE(CraftingMenu_SelectedModdableItem, 0x0144C240)
DECLARE_EVENT_SOURCE(CraftingMenu_SelectedRecipe, 0x0144C420)
DECLARE_EVENT_SOURCE(CraftingMenu_SessionSummaryEvent, 0x0144C560)
DECLARE_EVENT_SOURCE(CraftingMenu_SetInspectControls, 0x0144C6A0)
DECLARE_EVENT_SOURCE(CraftingMenu_ToggleTracking, 0x0144C600)
DECLARE_EVENT_SOURCE(CraftingMenu_ViewingModdableItem, 0x0144C2E0)
//DECLARE_EVENT_SOURCE(CreationUninstalledEvent, 0x01350880)
DECLARE_EVENT_SOURCE(DataMenu_CloseMenu, 0x016662C0)
DECLARE_EVENT_SOURCE(DataMenu_ClosedForSubMenu, 0x01666360)
DECLARE_EVENT_SOURCE(DataMenu_Missions, 0x01666540)
//DECLARE_EVENT_SOURCE(DataMenu_OpenPauseMenu, 0x01606520)
DECLARE_EVENT_SOURCE(DataMenu_PlotToLocation, 0x01665DC0)
DECLARE_EVENT_SOURCE(DataMenu_Reopened, 0x01666220)
DECLARE_EVENT_SOURCE(DataMenu_SelectedAttributesMenu, 0x01665F00)
DECLARE_EVENT_SOURCE(DataMenu_SelectedInventoryMenu, 0x01665FA0)
DECLARE_EVENT_SOURCE(DataMenu_SelectedMapMenu, 0x01666040)
DECLARE_EVENT_SOURCE(DataMenu_SelectedPowersMenu, 0x01665E60)
DECLARE_EVENT_SOURCE(DataMenu_SelectedShipMenu, 0x016660E0)
DECLARE_EVENT_SOURCE(DataMenu_SelectedStatusMenu, 0x01666180)
DECLARE_EVENT_SOURCE(DataMenu_SetMenuForQuickEntry, 0x016664A0)
DECLARE_EVENT_SOURCE(DataMenu_SetPaperDollActive, 0x01666400)
//DECLARE_EVENT_SOURCE(DataMenu_StartCloseAnim, 0x013FB180)
DECLARE_EVENT_SOURCE(DataSlateButtons_acceptClicked, 0x015E52C0)
DECLARE_EVENT_SOURCE(DataSlateButtons_cancelClicked, 0x015E5220)
DECLARE_EVENT_SOURCE(DataSlateMenu_playSFX, 0x015E5360)
DECLARE_EVENT_SOURCE(DataSlateMenu_toggleAudio, 0x015E5400)
DECLARE_EVENT_SOURCE(DefaultObjectsReadyEvent::Event, 0x00BCF4C0)
//DECLARE_EVENT_SOURCE(DeferredDeleter::QueueStatusEvent, 0x0180A6F0)
DECLARE_EVENT_SOURCE(DialogueMenu_CompleteExit, 0x01595BE0)
DECLARE_EVENT_SOURCE(DialogueMenu_OnDialogueSelect, 0x01EBA4F0)
DECLARE_EVENT_SOURCE(DialogueMenu_OnListVisibilityChange, 0x01EBA310)
DECLARE_EVENT_SOURCE(DialogueMenu_OnPersuasionAutoWin, 0x01EBA590)
DECLARE_EVENT_SOURCE(DialogueMenu_OnScriptedDialogueSelect, 0x01EBA270)
DECLARE_EVENT_SOURCE(DialogueMenu_RequestExit, 0x01EBA3B0)
DECLARE_EVENT_SOURCE(DialogueMenu_RequestSkipDialogue, 0x01EBA450)
DECLARE_EVENT_SOURCE(DisplayFatigueWarningEvent, 0x015BADE0)
//DECLARE_EVENT_SOURCE(DocAcceptMenu_Accept, 0x01335B90)
//DECLARE_EVENT_SOURCE(DynNavMeshOpRecord::CompleteEvent, 0x006862D0)
//DECLARE_EVENT_SOURCE(DynamicNavMeshBuildCompleteEvent, 0x003B4240)
DECLARE_EVENT_SOURCE(EndLoadGameEvent, 0x0035D4E0)
//DECLARE_EVENT_SOURCE(ExitVehicleEvent, 0x0132E070)
DECLARE_EVENT_SOURCE(ExperienceMeterDisplayData, 0x015BA100)
DECLARE_EVENT_SOURCE(FaderMenuDisplayState, 0x01EBBE70)
DECLARE_EVENT_SOURCE(FavoritesMenu_AssignQuickkey, 0x01EC3DD0)
DECLARE_EVENT_SOURCE(FavoritesMenu_UseQuickkey, 0x01EC3D30)
//DECLARE_EVENT_SOURCE(GameActiveChangeEvent, 0x01372540)
//DECLARE_EVENT_SOURCE(GameResetEvent, 0x01830280)
DECLARE_EVENT_SOURCE(GameStalledEvent, 0x027F46A0)
DECLARE_EVENT_SOURCE(GlobalFunc_CloseAllMenus, 0x015AEFE0)
DECLARE_EVENT_SOURCE(GlobalFunc_CloseMenu, 0x015AF080)
DECLARE_EVENT_SOURCE(GlobalFunc_PlayMenuSound, 0x015AF260)
DECLARE_EVENT_SOURCE(GlobalFunc_StartGameRender, 0x015AF1C0)
DECLARE_EVENT_SOURCE(GlobalFunc_UserEvent, 0x015AF120)
DECLARE_EVENT_SOURCE(HUDActivityIncreaseEvent, 0x002B70B0)
DECLARE_EVENT_SOURCE(HUDCrewBuffMessageEvent, 0x014408B0)
DECLARE_EVENT_SOURCE(HUDModeEvent, 0x0146D760)
DECLARE_EVENT_SOURCE(HUDNotificationEvent, 0x015C77B0)
DECLARE_EVENT_SOURCE(HUDNotification_MissionActiveWidgetUpdate, 0x015C7710)
DECLARE_EVENT_SOURCE(HUDNotification_OpenDataMenu, 0x015C75D0)
DECLARE_EVENT_SOURCE(HUDNotification_OpenMissionMenu, 0x015C7530)
DECLARE_EVENT_SOURCE(HUDNotification_SetMissionActive, 0x015C7670)
DECLARE_EVENT_SOURCE(HUDRolloverActivationButtonEvent, 0x0146D620)
DECLARE_EVENT_SOURCE(HUDRolloverActivationQCItemPressEvent, 0x0146D580)
DECLARE_EVENT_SOURCE(HUDWeaponWorldFOVMultChangedEvent, 0x00859CA0)
DECLARE_EVENT_SOURCE(HangarShipSelection_ChangeSystemDisplay, 0x013F27A0)
DECLARE_EVENT_SOURCE(HangarShipSelection_RepairShip, 0x013F2660)
DECLARE_EVENT_SOURCE(HangarShipSelection_UpgradeSystem, 0x013F2700)
DECLARE_EVENT_SOURCE(HomeShipSetEvent, 0x0130D650)
DECLARE_EVENT_SOURCE(ImageFixtureEvent_RequestImage, 0x0255B7D0)
DECLARE_EVENT_SOURCE(ImageFixtureEvent_UnregisterImage, 0x0255B730)
DECLARE_EVENT_SOURCE(InventoryItemEvent::Event, 0x012D4B20)
DECLARE_EVENT_SOURCE(InventoryMenu_Change3DView, 0x0145AC40)
DECLARE_EVENT_SOURCE(InventoryMenu_DropItem, 0x015ECF20)
DECLARE_EVENT_SOURCE(InventoryMenu_HideModel, 0x015ED060)
DECLARE_EVENT_SOURCE(InventoryMenu_LoadModel, 0x015ED100)
DECLARE_EVENT_SOURCE(InventoryMenu_OnEnterCategory, 0x015ECC00)
DECLARE_EVENT_SOURCE(InventoryMenu_OpenCargoHold, 0x015ECE80)
DECLARE_EVENT_SOURCE(InventoryMenu_PaperDollTryOn, 0x0145ABA0)
DECLARE_EVENT_SOURCE(InventoryMenu_ResetPaperDollInv, 0x0145AB00)
DECLARE_EVENT_SOURCE(InventoryMenu_SelectItem, 0x015ECFC0)
DECLARE_EVENT_SOURCE(InventoryMenu_SetMouseOverModel, 0x015ECCA0)
//DECLARE_EVENT_SOURCE(InventoryMenu_StartCloseAnim, 0x0158B230)
DECLARE_EVENT_SOURCE(InventoryMenu_ToggleFavorite, 0x015ECDE0)
DECLARE_EVENT_SOURCE(InventoryMenu_ToggleHelmet, 0x014DD590)
DECLARE_EVENT_SOURCE(InventoryMenu_ToggleSuit, 0x014DD4F0)
DECLARE_EVENT_SOURCE(Inventory_SetSort, 0x0146D4E0)
DECLARE_EVENT_SOURCE(LevelIncrease::Event, 0x01A3C890)
DECLARE_EVENT_SOURCE(LevelUp_AnimFinished, 0x015BA060)
DECLARE_EVENT_SOURCE(LevelUp_OnWidgetShown, 0x015B9E80)
DECLARE_EVENT_SOURCE(LevelUp_OpenDataMenu, 0x015B9F20)
DECLARE_EVENT_SOURCE(LevelUp_ShowSkills, 0x015B9FC0)
DECLARE_EVENT_SOURCE(LoadScreenEndEvent, 0x005893E0)
DECLARE_EVENT_SOURCE(LoadScreenStartEvent, 0x00589480)
DECLARE_EVENT_SOURCE(LoadingMenu_RefreshText, 0x01ECA2E0)
DECLARE_EVENT_SOURCE(LocationTextWidget_FinishedQueue, 0x015B9DE0)
DECLARE_EVENT_SOURCE(MainMenu_ActionCanceled, 0x01ED2520)
DECLARE_EVENT_SOURCE(MainMenu_ActionConfirmed, 0x01ED25C0)
DECLARE_EVENT_SOURCE(MainMenu_ConfirmLoad, 0x01ED23E0)
DECLARE_EVENT_SOURCE(MainMenu_DeleteSave, 0x01ED2340)
//DECLARE_EVENT_SOURCE(MainMenu_LegalScreenComplete, 0x01E5BAE0)
DECLARE_EVENT_SOURCE(MainMenu_SetCharacter, 0x01ED22A0)
DECLARE_EVENT_SOURCE(MainMenu_StartAction, 0x01ED2660)
DECLARE_EVENT_SOURCE(MainMenu_StartLoad, 0x01ED2480)
DECLARE_EVENT_SOURCE(MainMenu_UploadSave, 0x01ED2200)
DECLARE_EVENT_SOURCE(MessageBoxMenu_OnBackOut, 0x01EDAD30)
DECLARE_EVENT_SOURCE(MessageBoxMenu_OnButtonPress, 0x01EDAE70)
DECLARE_EVENT_SOURCE(MessageBoxMenu_OnScriptedButtonPress, 0x01EDADD0)
DECLARE_EVENT_SOURCE(MissionBoard_MissionEntryChanged, 0x015F25A0)
DECLARE_EVENT_SOURCE(MissionBoard_MissionEntryPressed, 0x015F2640)
DECLARE_EVENT_SOURCE(MissionMenu_ClearState, 0x015E02F0)
DECLARE_EVENT_SOURCE(MissionMenu_PlotToLocation, 0x015E0610)
DECLARE_EVENT_SOURCE(MissionMenu_RejectQuest, 0x015E04D0)
DECLARE_EVENT_SOURCE(MissionMenu_SaveCategoryIndex, 0x015E0390)
DECLARE_EVENT_SOURCE(MissionMenu_SaveOpenedId, 0x015E0430)
DECLARE_EVENT_SOURCE(MissionMenu_ShowItemLocation, 0x015E06B0)
//DECLARE_EVENT_SOURCE(MissionMenu_ToggleQTDisplay, 0x0157EBC0)
DECLARE_EVENT_SOURCE(MissionMenu_ToggleTrackingQuest, 0x015E0570)
DECLARE_EVENT_SOURCE(ModelReferenceEffectEvents::ReferenceEffectFinished, 0x01772CC0)
DECLARE_EVENT_SOURCE(MonocleMenu_Bioscan, 0x015FD3A0)
DECLARE_EVENT_SOURCE(MonocleMenu_FastTravel, 0x015FCEA0)
DECLARE_EVENT_SOURCE(MonocleMenu_Harvest, 0x015FD440)
DECLARE_EVENT_SOURCE(MonocleMenu_Initialize, 0x015FD620)
//DECLARE_EVENT_SOURCE(MonocleMenu_OpenDoor, 0x0159B470)
DECLARE_EVENT_SOURCE(MonocleMenu_Outpost, 0x015FD4E0)
DECLARE_EVENT_SOURCE(MonocleMenu_PhotoMode, 0x015FD1C0)
DECLARE_EVENT_SOURCE(MonocleMenu_Shutdown, 0x015FD580)
DECLARE_EVENT_SOURCE(MonocleMenu_SocialSpell, 0x015FD300)
DECLARE_EVENT_SOURCE(MonocleMenu_StartContainerView, 0x015FCFE0)
DECLARE_EVENT_SOURCE(MonocleMenu_StopContainerView, 0x015FCF40)
DECLARE_EVENT_SOURCE(MonocleMenu_SurfaceMap, 0x015FD260)
DECLARE_EVENT_SOURCE(MonocleMenu_UseListScrollControls, 0x015FCE00)
DECLARE_EVENT_SOURCE(MonocleMenu_ZoomIn, 0x015FD120)
DECLARE_EVENT_SOURCE(MonocleMenu_ZoomOut, 0x015FD080)
DECLARE_EVENT_SOURCE(OpenContainerMenuEventData, 0x0146D800)
DECLARE_EVENT_SOURCE(OpenContainerMenuFromListenerEvent, 0x0146D6C0)
DECLARE_EVENT_SOURCE(PauseMenu_ActionCanceled, 0x0166F080)
DECLARE_EVENT_SOURCE(PauseMenu_ConfirmAction, 0x0166F120)
DECLARE_EVENT_SOURCE(PauseMenu_ConfirmLoad, 0x0166EF40)
DECLARE_EVENT_SOURCE(PauseMenu_ConfirmSave, 0x0166ED60)
DECLARE_EVENT_SOURCE(PauseMenu_DeleteSave, 0x0166EEA0)
DECLARE_EVENT_SOURCE(PauseMenu_QuitToDesktop, 0x0166ECC0)
DECLARE_EVENT_SOURCE(PauseMenu_SetCharacter, 0x0166EE00)
DECLARE_EVENT_SOURCE(PauseMenu_StartAction, 0x0166F1C0)
DECLARE_EVENT_SOURCE(PauseMenu_StartLoad, 0x0166EFE0)
DECLARE_EVENT_SOURCE(PauseMenu_UploadSave, 0x0166EC20)
DECLARE_EVENT_SOURCE(PerkChanged::Event, 0x00CA3910)
DECLARE_EVENT_SOURCE(PhotoGallery_DeletePhoto, 0x013D88D0)
DECLARE_EVENT_SOURCE(PhotoMode_InitializeCategory, 0x016039B0)
//DECLARE_EVENT_SOURCE(PhotoMode_RefineSetting, 0x015A1D50)
DECLARE_EVENT_SOURCE(PhotoMode_ResetToDefaults, 0x01603910)
DECLARE_EVENT_SOURCE(PhotoMode_SliderChanged, 0x01603870)
DECLARE_EVENT_SOURCE(PhotoMode_StepperChanged, 0x016037D0)
DECLARE_EVENT_SOURCE(PhotoMode_TakeSnapshot, 0x01603730)
DECLARE_EVENT_SOURCE(PhotoMode_ToggleHelmet, 0x016035F0)
DECLARE_EVENT_SOURCE(PhotoMode_ToggleUI, 0x01603690)
DECLARE_EVENT_SOURCE(PickRefStateChangedEvent, 0x005F79E0)
DECLARE_EVENT_SOURCE(PickRefUpdateEvent, 0x00F4F3E0)
DECLARE_EVENT_SOURCE(PickpocketMenu_OnItemSelect, 0x01607F80)
DECLARE_EVENT_SOURCE(PlayBink_CloseMenu, 0x01670140)
DECLARE_EVENT_SOURCE(PlayerAutoAimActorEvent, 0x01A71C00)
DECLARE_EVENT_SOURCE(PlayerCharacterQuestEvent::Event, 0x00D0DC70)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerIronSightsEndEvent, 0x012C42E0)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerIronSightsStartEvent, 0x012C4380)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerJumpPressEvent, 0x012BC540)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerJumpReleaseEvent, 0x012BC4A0)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerZeroGSprintJustPressedEvent, 0x012BE560)
DECLARE_EVENT_SOURCE(PlayerControls::PlayerZeroGSprintReleasedEvent, 0x012BE4C0)
DECLARE_EVENT_SOURCE(PlayerCrosshairModeEvent, 0x01488FA0)
DECLARE_EVENT_SOURCE(PlayerDetectionLevelChangeEvent, 0x01495B70)
//DECLARE_EVENT_SOURCE(PlayerFastTravelFromVehicleEvent, 0x0211EFB0)
DECLARE_EVENT_SOURCE(PlayerInCombatChangeEvent, 0x01A78DE0)
DECLARE_EVENT_SOURCE(PlayerSetWeaponStateEvent, 0x015CAAF0)
DECLARE_EVENT_SOURCE(PlayerSneakingChangeEvent, 0x012BE010)
DECLARE_EVENT_SOURCE(PlayerUpdateEvent, 0x014DD630)
DECLARE_EVENT_SOURCE(PowersMenu_ActivateEssence, 0x013DFA10)
DECLARE_EVENT_SOURCE(PowersMenu_EquipPower, 0x013DFB50)
DECLARE_EVENT_SOURCE(PowersMenu_FavoritePower, 0x013DFAB0)
//DECLARE_EVENT_SOURCE(ProjectileBeginUpdateEvent, 0x01AC2CB0)
//DECLARE_EVENT_SOURCE(ProjectileKillEvent, 0x01AC2CB0)
//DECLARE_EVENT_SOURCE(QueuedReferenceFinishedEvent, 0x0055FBE0)
DECLARE_EVENT_SOURCE(ReferenceCellLoadedTemps, 0x00927D60)
DECLARE_EVENT_SOURCE(ReferenceQueuedEvent, 0x00572190)
//DECLARE_EVENT_SOURCE(RefreshDataMenuForSkillsChangeEvent, 0x013FB0E0)
DECLARE_EVENT_SOURCE(Refuel_Accept, 0x01628820)
DECLARE_EVENT_SOURCE(Refuel_Cancel, 0x01628780)
DECLARE_EVENT_SOURCE(Research::ResearchProgressEvent, 0x01800A30)
DECLARE_EVENT_SOURCE(ResearchMenu_AddMaterial, 0x01612EF0)
DECLARE_EVENT_SOURCE(ResearchMenu_CategorySelected, 0x016130D0)
DECLARE_EVENT_SOURCE(ResearchMenu_ExitMenu, 0x01612E50)
DECLARE_EVENT_SOURCE(ResearchMenu_HideModel, 0x01612DB0)
DECLARE_EVENT_SOURCE(ResearchMenu_PreviewProject, 0x01613030)
DECLARE_EVENT_SOURCE(ResearchMenu_ProjectViewed, 0x01612F90)
DECLARE_EVENT_SOURCE(ResearchMenu_SetInspectControls, 0x01612D10)
DECLARE_EVENT_SOURCE(ResearchMenu_ToggleTrackingProject, 0x01612C70)
DECLARE_EVENT_SOURCE(ResetHistoryDataEvent, 0x00841680)
//DECLARE_EVENT_SOURCE(ResourceServerLogDumped, 0x02774EF0)
DECLARE_EVENT_SOURCE(Reticle_OnLongAnimFinished, 0x01679150)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceAttach, 0x003E9D30)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceCleared3d, 0x0067FC80)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceDestroy, 0x0067FB40)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceDetach, 0x003E9C90)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceInit, 0x0067FBE0)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceRecycle, 0x0067FAA0)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::ReferenceSet3d, 0x0067FD20)
DECLARE_EVENT_SOURCE(RuntimeComponentDBFactory::Release3DRelatedData, 0x00680840)
DECLARE_EVENT_SOURCE(SaveLoadEvent, 0x012EDC50)
DECLARE_EVENT_SOURCE(SaveLoadMessageStringEvent, 0x015BFC70)
DECLARE_EVENT_SOURCE(SecurityMenu_BackOutKey, 0x016213A0)
DECLARE_EVENT_SOURCE(SecurityMenu_CloseMenu, 0x016214E0)
DECLARE_EVENT_SOURCE(SecurityMenu_ConfirmExit, 0x016211C0)
DECLARE_EVENT_SOURCE(SecurityMenu_EliminateUnusedKeys, 0x01621260)
DECLARE_EVENT_SOURCE(SecurityMenu_GetRingHint, 0x01621300)
DECLARE_EVENT_SOURCE(SecurityMenu_SelectNewKey, 0x01621120)
DECLARE_EVENT_SOURCE(SecurityMenu_TryUseKey, 0x01621440)
DECLARE_EVENT_SOURCE(SettingsPanel_CheckBoxChanged, 0x01537190)
DECLARE_EVENT_SOURCE(SettingsPanel_ClearBinding, 0x01536F10)
//DECLARE_EVENT_SOURCE(SettingsPanel_LinkClicked, 0x014D64F0)
DECLARE_EVENT_SOURCE(SettingsPanel_OpenCategory, 0x01536FB0)
DECLARE_EVENT_SOURCE(SettingsPanel_OpenSettings, 0x01537050)
DECLARE_EVENT_SOURCE(SettingsPanel_RemapConfirmed, 0x01536E70)
DECLARE_EVENT_SOURCE(SettingsPanel_RemapMode, 0x015374B0)
DECLARE_EVENT_SOURCE(SettingsPanel_ResetToDefaults, 0x015370F0)
DECLARE_EVENT_SOURCE(SettingsPanel_SaveControls, 0x01537410)
DECLARE_EVENT_SOURCE(SettingsPanel_SaveSettings, 0x01537370)
DECLARE_EVENT_SOURCE(SettingsPanel_SliderChanged, 0x015372D0)
DECLARE_EVENT_SOURCE(SettingsPanel_StepperChanged, 0x01537230)
DECLARE_EVENT_SOURCE(SettingsPanel_ValidateControls, 0x01536DD0)
//DECLARE_EVENT_SOURCE(SettingsSavedEvent, 0x014D6380)
DECLARE_EVENT_SOURCE(ShipBuilder_CloseAllMenus, 0x004EC960)
DECLARE_EVENT_SOURCE(ShipCameraStateToggled, 0x00FA4A00)
DECLARE_EVENT_SOURCE(ShipCrewAssignMenu_Assign, 0x01626F80)
DECLARE_EVENT_SOURCE(ShipCrewAssignMenu_Unassign, 0x01626EE0)
DECLARE_EVENT_SOURCE(ShipCrewMenu_Close, 0x013F2520)
DECLARE_EVENT_SOURCE(ShipCrewMenu_OpenAssignMenu, 0x01541F40)
DECLARE_EVENT_SOURCE(ShipCrewMenu_SetSort, 0x01541FE0)
DECLARE_EVENT_SOURCE(ShipCrewMenu_ViewedItem, 0x01627030)
DECLARE_EVENT_SOURCE(ShipEditor_ChangeModuleCategory, 0x004BC2F0)
DECLARE_EVENT_SOURCE(ShipEditor_OnColorPickerControlChanged, 0x00399E70)
DECLARE_EVENT_SOURCE(ShipEditor_OnColorPickerTabChanged, 0x00399FB0)
DECLARE_EVENT_SOURCE(ShipEditor_OnColorSliderMouseInput, 0x00399DD0)
DECLARE_EVENT_SOURCE(ShipEditor_OnExitConfirmCancel, 0x004AA4E0)
DECLARE_EVENT_SOURCE(ShipEditor_OnExitConfirmExit, 0x004AA580)
DECLARE_EVENT_SOURCE(ShipEditor_OnExitConfirmSaveAndExit, 0x004AA440)
DECLARE_EVENT_SOURCE(ShipEditor_OnFlightCheckTabChanged, 0x004B06E0)
DECLARE_EVENT_SOURCE(ShipEditor_OnHintButtonActivated, 0x004EC8C0)
DECLARE_EVENT_SOURCE(ShipEditor_OnRecentColorSwatchClicked, 0x00399F10)
DECLARE_EVENT_SOURCE(ShipEditor_OnRenameEndEditText, 0x004B6410)
DECLARE_EVENT_SOURCE(ShipEditor_OnRenameInputCancelled, 0x004B64B0)
DECLARE_EVENT_SOURCE(ShipEditor_OnWeaponGroupChanged, 0x004B0640)
DECLARE_EVENT_SOURCE(ShipEditor_PreviewShipPart, 0x004BC390)
DECLARE_EVENT_SOURCE(ShipEditor_PreviewUpgrade, 0x00393E00)
DECLARE_EVENT_SOURCE(ShipEditor_RemoveAll3D, 0x004EC820)
DECLARE_EVENT_SOURCE(ShipEditor_SelectedShipPart, 0x004BC430)
DECLARE_EVENT_SOURCE(ShipEditor_SelectedUpgrade, 0x00393D60)
DECLARE_EVENT_SOURCE(ShipEditor_SystemSelected, 0x0038D5D0)
DECLARE_EVENT_SOURCE(ShipHudQuickContainer_TransferItem, 0x01679290)
DECLARE_EVENT_SOURCE(ShipHudQuickContainer_TransferMenu, 0x0156F8B0)
DECLARE_EVENT_SOURCE(ShipHud_AbortJump, 0x016791F0)
DECLARE_EVENT_SOURCE(ShipHud_Activate, 0x0156F950)
DECLARE_EVENT_SOURCE(ShipHud_BodyViewMarkerDimensions, 0x0156F130)
DECLARE_EVENT_SOURCE(ShipHud_ChangeComponentSelection, 0x0156FC70)
DECLARE_EVENT_SOURCE(ShipHud_CloseMenu, 0x0156FDB0)
DECLARE_EVENT_SOURCE(ShipHud_Deselect, 0x0156F9F0)
DECLARE_EVENT_SOURCE(ShipHud_DockRequested, 0x01679330)
DECLARE_EVENT_SOURCE(ShipHud_FarTravel, 0x0156EFF0)
DECLARE_EVENT_SOURCE(ShipHud_HailAccepted, 0x0156F590)
DECLARE_EVENT_SOURCE(ShipHud_HailCancelled, 0x0156F630)
DECLARE_EVENT_SOURCE(ShipHud_HailShip, 0x016793D0)
DECLARE_EVENT_SOURCE(ShipHud_JumpToQuestMarker, 0x0156F450)
DECLARE_EVENT_SOURCE(ShipHud_Land, 0x0156F810)
DECLARE_EVENT_SOURCE(ShipHud_LandingMarkerMap, 0x0156F6D0)
DECLARE_EVENT_SOURCE(ShipHud_Map, 0x0156F770)
DECLARE_EVENT_SOURCE(ShipHud_OnMonocleToggle, 0x0156F4F0)
DECLARE_EVENT_SOURCE(ShipHud_OpenPhotoMode, 0x0156F1D0)
DECLARE_EVENT_SOURCE(ShipHud_Repair, 0x0156F090)
DECLARE_EVENT_SOURCE(ShipHud_SetTargetMode, 0x0156F3B0)
DECLARE_EVENT_SOURCE(ShipHud_Target, 0x0156FA90)
DECLARE_EVENT_SOURCE(ShipHud_TargetShipSystem, 0x0156F310)
DECLARE_EVENT_SOURCE(ShipHud_UntargetShipSystem, 0x0156F270)
DECLARE_EVENT_SOURCE(ShipHud_UpdateComponentPower, 0x0156FD10)
DECLARE_EVENT_SOURCE(ShipHud_UpdateTargetPanelRect, 0x01678B90)
DECLARE_EVENT_SOURCE(ShowCustomWatchAlert, 0x0149BA20)
DECLARE_EVENT_SOURCE(ShowHUDMessageEvent, 0x014915A0)
DECLARE_EVENT_SOURCE(ShowLongShipBootup, 0x0156FBD0)
DECLARE_EVENT_SOURCE(ShowingQuestMarketTextEvent, 0x01485B00)
DECLARE_EVENT_SOURCE(SkillsMenu_Accept, 0x0162E910)
DECLARE_EVENT_SOURCE(SkillsMenu_AddPatch, 0x0162E870)
DECLARE_EVENT_SOURCE(SkillsMenu_Cancel, 0x0162E9B0)
DECLARE_EVENT_SOURCE(SkillsMenu_ChangeCursorVisibility, 0x0162E7D0)
DECLARE_EVENT_SOURCE(SkillsMenu_SaveLastCategory, 0x0162E730)
DECLARE_EVENT_SOURCE(SleepWaitMenu_InterruptRest, 0x01EDF1E0)
DECLARE_EVENT_SOURCE(SleepWaitMenu_StartRest, 0x01EDF280)
DECLARE_EVENT_SOURCE(SnapTemplateUtils::SnapReplaceEvent, 0x00941640)
DECLARE_EVENT_SOURCE(Spaceship::BoughtEvent, 0x0215FD50)
DECLARE_EVENT_SOURCE(Spaceship::ContrabandScanWarningEvent, 0x02160570)
DECLARE_EVENT_SOURCE(Spaceship::DockEvent, 0x0215FE90)
DECLARE_EVENT_SOURCE(Spaceship::DynamicNavmeshCompleted, 0x02160250)
DECLARE_EVENT_SOURCE(Spaceship::FarTravelEvent, 0x02160430)
DECLARE_EVENT_SOURCE(Spaceship::GravJumpEvent, 0x01678ED0)
DECLARE_EVENT_SOURCE(Spaceship::LandedSetEvent, 0x01678E30)
DECLARE_EVENT_SOURCE(Spaceship::LandingEvent, 0x021602F0)
DECLARE_EVENT_SOURCE(Spaceship::PlanetScanEvent, 0x021604D0)
DECLARE_EVENT_SOURCE(Spaceship::PlayerMovementOutputEvent, 0x0156FB30)
DECLARE_EVENT_SOURCE(Spaceship::RampDownEvent, 0x0215FA30)
DECLARE_EVENT_SOURCE(Spaceship::RefueledEvent, 0x0215FDF0)
DECLARE_EVENT_SOURCE(Spaceship::RegisteredEvent, 0x0215FB70)
DECLARE_EVENT_SOURCE(Spaceship::ShieldEvent, 0x0215F990)
DECLARE_EVENT_SOURCE(Spaceship::ShipAddedEvent, 0x0215FAD0)
DECLARE_EVENT_SOURCE(Spaceship::ShipCollisionEvent, 0x0215F8F0)
DECLARE_EVENT_SOURCE(Spaceship::ShipCustomizedEvent, 0x0215F7B0)
DECLARE_EVENT_SOURCE(Spaceship::SoldEvent, 0x0215FCB0)
DECLARE_EVENT_SOURCE(Spaceship::SystemDamagedEvent, 0x02160070)
DECLARE_EVENT_SOURCE(Spaceship::SystemPowerAllocationEvent, 0x02160110)
DECLARE_EVENT_SOURCE(Spaceship::SystemPowerChangeEvent, 0x021601B0)
DECLARE_EVENT_SOURCE(Spaceship::SystemRepairedBIEvent, 0x0215FF30)
DECLARE_EVENT_SOURCE(Spaceship::SystemRepairedEvent, 0x0215FFD0)
DECLARE_EVENT_SOURCE(Spaceship::TakeDamagEvent, 0x0215F850)
DECLARE_EVENT_SOURCE(Spaceship::TakeOffEvent, 0x02160390)
DECLARE_EVENT_SOURCE(SpaceshipBIEvents::ShipPowerAllocationBIEventSent, 0x0179FF60)
DECLARE_EVENT_SOURCE(SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent, 0x01310E10)
DECLARE_EVENT_SOURCE(StarMap::PlanetTraitKnownEvent, 0x007BFEF0)
DECLARE_EVENT_SOURCE(StarMapMenu_ExecuteRoute, 0x016C3420)
DECLARE_EVENT_SOURCE(StarMapMenu_Galaxy_FocusSystem, 0x016B26C0)
DECLARE_EVENT_SOURCE(StarMapMenu_LandingInputInProgress, 0x01693CC0)
DECLARE_EVENT_SOURCE(StarMapMenu_MarkerGroupContainerVisibilityChanged, 0x01693AE0)
DECLARE_EVENT_SOURCE(StarMapMenu_MarkerGroupEntryClicked, 0x01693A40)
DECLARE_EVENT_SOURCE(StarMapMenu_MarkerGroupEntryHoverChanged, 0x016939A0)
DECLARE_EVENT_SOURCE(StarMapMenu_OnCancel, 0x016C31A0)
DECLARE_EVENT_SOURCE(StarMapMenu_OnClearRoute, 0x016C34C0)
DECLARE_EVENT_SOURCE(StarMapMenu_OnExitStarMap, 0x016C32E0)
DECLARE_EVENT_SOURCE(StarMapMenu_OnGalaxyViewInitialized, 0x016B2620)
DECLARE_EVENT_SOURCE(StarMapMenu_OnHintButtonClicked, 0x016C3380)
DECLARE_EVENT_SOURCE(StarMapMenu_OnOutpostEntrySelected, 0x016C3240)
DECLARE_EVENT_SOURCE(StarMapMenu_QuickSelectChange, 0x016A4CC0)
DECLARE_EVENT_SOURCE(StarMapMenu_ReadyToClose, 0x016C3100)
DECLARE_EVENT_SOURCE(StarMapMenu_ScanPlanet, 0x01693D60)
DECLARE_EVENT_SOURCE(StarMapMenu_SelectedLandingSite, 0x01693B80)
DECLARE_EVENT_SOURCE(StarMapMenu_SelectedLandingSiteFailed, 0x01692FE0)
DECLARE_EVENT_SOURCE(StarMapMenu_ShowRealCursor, 0x01693C20)
DECLARE_EVENT_SOURCE(StartLoadGameEvent, 0x0035D580)
DECLARE_EVENT_SOURCE(StartOutpostFromListenerEvent, 0x01464D90)
//DECLARE_EVENT_SOURCE(SurfaceMapMenu_EnablePointCloud, 0x01682090)
DECLARE_EVENT_SOURCE(SurfaceMapMenu_MarkerClicked, 0x016E27C0)
DECLARE_EVENT_SOURCE(SurfaceMapMenu_TryPlaceCustomMarker, 0x016E2720)
DECLARE_EVENT_SOURCE(TESCellCriticalRefsAttachedEvent, 0x005810B0)
DECLARE_EVENT_SOURCE(TESCellFullyLoadedEvent, 0x005810B0)
DECLARE_EVENT_SOURCE(TESCellReference3DAttachEvent, 0x0046B0B0)
//DECLARE_EVENT_SOURCE(TESFilesCompiledEvent, 0x005A6830)
//DECLARE_EVENT_SOURCE(TESObjectREFRDuplicate::Event, 0x00B611F0)
DECLARE_EVENT_SOURCE(TESOpenCloseEvent, 0x01883440)
DECLARE_EVENT_SOURCE(TESQuestEvent::Event, 0x00D0DC70)
DECLARE_EVENT_SOURCE(TESQuestRewardEvent, 0x00856A50)
DECLARE_EVENT_SOURCE(TESSceneEvent, 0x00CB4690)
DECLARE_EVENT_SOURCE(TESUniqueIDChangeEvent, 0x00B64FC0)
DECLARE_EVENT_SOURCE(TakeoffMenu_CloseMenu, 0x01678C50)
DECLARE_EVENT_SOURCE(TakeoffMenu_ExitShip, 0x01678CF0)
DECLARE_EVENT_SOURCE(TakeoffMenu_Launch, 0x01678D90)
DECLARE_EVENT_SOURCE(TargetHitEvent, 0x01489180)
DECLARE_EVENT_SOURCE(TerminalMenu_CancelEvent, 0x016FE280)
DECLARE_EVENT_SOURCE(Terminal_CloseAllViews, 0x016FE000)
DECLARE_EVENT_SOURCE(Terminal_CloseTopView, 0x016FE0A0)
DECLARE_EVENT_SOURCE(Terminal_CloseView, 0x016FE140)
DECLARE_EVENT_SOURCE(Terminal_MenuItemClick, 0x016FE1E0)
DECLARE_EVENT_SOURCE(TestMenu_DoAction, 0x01707AA0)
DECLARE_EVENT_SOURCE(TestMenu_ExitMenu, 0x01707960)
DECLARE_EVENT_SOURCE(TestMenu_ShowImages, 0x01707B40)
DECLARE_EVENT_SOURCE(TestMenu_ShowResources, 0x01707BE0)
DECLARE_EVENT_SOURCE(TestMenu_TestAll, 0x01707A00)
DECLARE_EVENT_SOURCE(TextInputMenu_EndEditText, 0x01714DB0)
DECLARE_EVENT_SOURCE(TextInputMenu_InputCanceled, 0x01714EF0)
DECLARE_EVENT_SOURCE(TextInputMenu_StartEditText, 0x01714E50)
//DECLARE_EVENT_SOURCE(TitleSequenceMenu_StartMusic, 0x01E6B910)
//DECLARE_EVENT_SOURCE(UGCServicesStatusChangeEvent, 0x01E5BA40)
DECLARE_EVENT_SOURCE(UIMenuChargenMenuDisablePaperdoll, 0x016596E0)
DECLARE_EVENT_SOURCE(UnlockedTerminalElementEvent, 0x01621080)
DECLARE_EVENT_SOURCE(UpdateActivateListenerEvent, 0x01462930)
DECLARE_EVENT_SOURCE(UpdateSceneRectEvent, 0x02555230)
//DECLARE_EVENT_SOURCE(VehicleDriverEnterExitEvent, 0x0211F050)
DECLARE_EVENT_SOURCE(WeaponGroupAssignmentMenu_ChangeWeaponAssignment, 0x00485810)
DECLARE_EVENT_SOURCE(WeaponGroupAssignmentMenu_OnHintButtonActivated, 0x004858B0)
DECLARE_EVENT_SOURCE(Workshop::CargoLinkAddedEvent, 0x00F4FCA0)
DECLARE_EVENT_SOURCE(Workshop::CargoLinkTargetChangedEvent, 0x00F4F520)
DECLARE_EVENT_SOURCE(Workshop::EnterOutpostBeaconModeEvent, 0x00F4F5C0)
DECLARE_EVENT_SOURCE(Workshop::ItemGrabbedEvent, 0x00F4F980)
DECLARE_EVENT_SOURCE(Workshop::ItemMovedEvent, 0x00F4F160)
DECLARE_EVENT_SOURCE(Workshop::ItemPlacedEvent, 0x00F4F840)
DECLARE_EVENT_SOURCE(Workshop::ItemProducedEvent, 0x00F4FA20)
DECLARE_EVENT_SOURCE(Workshop::ItemRemovedEvent, 0x00F4F8E0)
DECLARE_EVENT_SOURCE(Workshop::ItemRepairedEvent, 0x00F4F0C0)
DECLARE_EVENT_SOURCE(Workshop::ItemScrappedEvent, 0x00F4FC00)
DECLARE_EVENT_SOURCE(Workshop::OutpostNameChangedEvent, 0x00F4F480)
DECLARE_EVENT_SOURCE(Workshop::OutpostPlacedEvent, 0x00F4F660)
DECLARE_EVENT_SOURCE(Workshop::PlacementStatusEvent, 0x00F4F340)
DECLARE_EVENT_SOURCE(Workshop::PowerOffEvent, 0x00F4FB60)
DECLARE_EVENT_SOURCE(Workshop::PowerOnEvent, 0x00F4FAC0)
DECLARE_EVENT_SOURCE(Workshop::SnapBehaviorCycledEvent, 0x00F4FE80)
DECLARE_EVENT_SOURCE(Workshop::WorkshopFlyCameraEvent, 0x00F4F200)
DECLARE_EVENT_SOURCE(Workshop::WorkshopItemPlacedEvent, 0x00F4F7A0)
DECLARE_EVENT_SOURCE(Workshop::WorkshopModeEvent, 0x00F4F2A0)
//DECLARE_EVENT_SOURCE(Workshop::WorkshopObjectModifiedBIEvent, 0x00F3AC60)
DECLARE_EVENT_SOURCE(Workshop::WorkshopOutputLinkEvent, 0x00F4F700)
DECLARE_EVENT_SOURCE(Workshop::WorkshopStatsChangedEvent, 0x00F4FD40)
DECLARE_EVENT_SOURCE(Workshop::WorkshopUpdateStatsEvent, 0x00F4FDE0)
DECLARE_EVENT_SOURCE(WorkshopActionButton_HoldFinished, 0x0173D5A0)
DECLARE_EVENT_SOURCE(WorkshopActionButton_HoldStopped, 0x0173D500)
DECLARE_EVENT_SOURCE(WorkshopBuilderMenu_ChangeBuildItem, 0x01718E20)
DECLARE_EVENT_SOURCE(WorkshopBuilderMenu_SelectedItem, 0x01718D80)
DECLARE_EVENT_SOURCE(WorkshopBuilderMenu_ToggleTracking, 0x01718CE0)
DECLARE_EVENT_SOURCE(WorkshopColorMode_ApplyColors, 0x0143EA50)
DECLARE_EVENT_SOURCE(WorkshopColorMode_SelectedTab, 0x0143E9B0)
DECLARE_EVENT_SOURCE(WorkshopColorMode_SliderChanged, 0x0143E910)
DECLARE_EVENT_SOURCE(WorkshopColorMode_SwatchChanged, 0x0143E870)
DECLARE_EVENT_SOURCE(WorkshopMenu_AttemptBuild, 0x0171F7E0)
DECLARE_EVENT_SOURCE(WorkshopMenu_CancelAction, 0x0171F560)
DECLARE_EVENT_SOURCE(WorkshopMenu_ChangeVariant, 0x0171F600)
DECLARE_EVENT_SOURCE(WorkshopMenu_ConnectionEvent, 0x0171F380)
DECLARE_EVENT_SOURCE(WorkshopMenu_ExitMenu, 0x0171F4C0)
DECLARE_EVENT_SOURCE(WorkshopMenu_MessageCallback, 0x0171F100)
DECLARE_EVENT_SOURCE(WorkshopMenu_SelectedCategory, 0x0171F6A0)
DECLARE_EVENT_SOURCE(WorkshopMenu_SelectedGridObject, 0x0171F740)
DECLARE_EVENT_SOURCE(WorkshopMenu_ShowExtras, 0x0171F2E0)
DECLARE_EVENT_SOURCE(WorkshopMenu_SwitchMode, 0x0171F420)
DECLARE_EVENT_SOURCE(WorkshopMenu_ToggleDistance, 0x0171F1A0)
DECLARE_EVENT_SOURCE(WorkshopMenu_ToggleTracking, 0x0171F060)
DECLARE_EVENT_SOURCE(WorkshopMenu_ToggleView, 0x0171F240)
DECLARE_EVENT_SOURCE(WorkshopQuickMenu_ConfirmAction, 0x017209B0)
DECLARE_EVENT_SOURCE(WorkshopQuickMenu_ExitMenu, 0x01720910)
DECLARE_EVENT_SOURCE(WorkshopShared_SetActionHandles, 0x0173D640)
DECLARE_EVENT_SOURCE(WorkshopShared_StartAction, 0x0173D6E0)
DECLARE_EVENT_SOURCE(WorkshopTargetMenu_TargetHovered, 0x01726E80)
DECLARE_EVENT_SOURCE(WorkshopTargetMenu_TargetPicked, 0x01726F20)
DECLARE_EVENT_SOURCE_EX(Activation::Event, 0x059777C0)
DECLARE_EVENT_SOURCE_EX(ActivityEvents::ActivityCompletedEvent, 0x05974898)
DECLARE_EVENT_SOURCE_EX(ActorCellChangeEvent, 0x059779A0)
DECLARE_EVENT_SOURCE_EX(ActorDamage::Event, 0x05979E98)
DECLARE_EVENT_SOURCE_EX(ActorHeadAttachedEvent, 0x059779C8)
DECLARE_EVENT_SOURCE_EX(ActorItemEquipped::Event, 0x05979E48)
DECLARE_EVENT_SOURCE_EX(ActorKill::Event, 0x05979E70)
DECLARE_EVENT_SOURCE_EX(AnimationGraphDependentEvent, 0x05978CB0)
DECLARE_EVENT_SOURCE_EX(AssaultCrime::Event, 0x05979F10)
DECLARE_EVENT_SOURCE_EX(AttachReference::Event, 0x0591B8B8)
DECLARE_EVENT_SOURCE_EX(BGSAffinityEventEvent, 0x059778B0)
DECLARE_EVENT_SOURCE_EX(BGSHavokWorldCreatedEvent, 0x059789B8)
DECLARE_EVENT_SOURCE_EX(BGSLocationLoadedEvent, 0x05977C20)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerCompanionDismiss, 0x05978760)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerCraftItemEvent, 0x05978800)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerCreateRobotEvent, 0x05978828)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerEnterVertibirdEvent, 0x059788C8)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerFallLongDistances, 0x05978788)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerFireWeaponEvent, 0x05978878)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerHealTeammateEvent, 0x059786E8)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerLoiteringBeginEvent, 0x05978710)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerLoiteringEndEvent, 0x05978738)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerModArmorWeaponEvent, 0x059787B0)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerModRobotEvent, 0x05978850)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerSwimmingEvent, 0x059788A0)
DECLARE_EVENT_SOURCE_EX(BGSOnPlayerUseWorkBenchEvent, 0x059788F0)
DECLARE_EVENT_SOURCE_EX(BGSOnSpeechChallengeAvailable, 0x05978918)
DECLARE_EVENT_SOURCE_EX(BGSRadiationDamageEvent, 0x059786C0)
//DECLARE_EVENT_SOURCE_EX(BNetCallbackHelper::ImageCallbackEvent, 0x0584C7D8)
//DECLARE_EVENT_SOURCE_EX(BNetCallbackHelper::UGCCallbackEvent, 0x0584C7B0)
//DECLARE_EVENT_SOURCE_EX(BSMusicEvent, 0x05859648)
//DECLARE_EVENT_SOURCE_EX(BSSysMonFrameCaptured, 0x0585A770)
DECLARE_EVENT_SOURCE_EX(Bleedout::Event, 0x05979FC0)
DECLARE_EVENT_SOURCE_EX(BooksRead::Event, 0x05975AF0)
DECLARE_EVENT_SOURCE_EX(Bounty::Event, 0x0597A090)
DECLARE_EVENT_SOURCE_EX(BuilderMenuSelectEvent, 0x05978A58)
//DECLARE_EVENT_SOURCE_EX(CelestialLocationDiscoveredEvent, 0x058AE488)
DECLARE_EVENT_SOURCE_EX(ChestLooted::Event, 0x0597A0B8)
DECLARE_EVENT_SOURCE_EX(ClearShipHudTarget::Event, 0x05979CA8)
DECLARE_EVENT_SOURCE_EX(ContractedDisease::Event, 0x05979FE8)
DECLARE_EVENT_SOURCE_EX(CrewAssignedEvent, 0x05977BD0)
DECLARE_EVENT_SOURCE_EX(CrewDismissedEvent, 0x05977BF8)
DECLARE_EVENT_SOURCE_EX(CriticalHitEvent::Event, 0x0597A068)
DECLARE_EVENT_SOURCE_EX(CustomMarkerUpdate::Event, 0x0597A0E0)
DECLARE_EVENT_SOURCE_EX(DaysJailed::Event, 0x0597A108)
DECLARE_EVENT_SOURCE_EX(DaysPassed::Event, 0x05979DD0)
DECLARE_EVENT_SOURCE_EX(DestroyedEvent, 0x05977C98)
DECLARE_EVENT_SOURCE_EX(DisarmedEvent::Event, 0x05979EC0)
DECLARE_EVENT_SOURCE_EX(EnteredUnity::Event, 0x0597A388)
DECLARE_EVENT_SOURCE_EX(FactionRankChange::Event, 0x05979EE8)
DECLARE_EVENT_SOURCE_EX(FinePaid::Event, 0x0597A130)
DECLARE_EVENT_SOURCE_EX(FirstThirdPersonSwitch::Event, 0x0597A428)
//DECLARE_EVENT_SOURCE_EX(GameplayOptionAppliedEvent, 0x058AE438)
//DECLARE_EVENT_SOURCE_EX(GameplayOptionChangedEvent, 0x058AE3E8)
//DECLARE_EVENT_SOURCE_EX(GameplayOptionUpdateFinishedEvent, 0x058AE410)
DECLARE_EVENT_SOURCE_EX(GrandTheftHorse::Event, 0x05979F88)
DECLARE_EVENT_SOURCE_EX(HideSubtitleEvent::Event, 0x05979BB0)
DECLARE_EVENT_SOURCE_EX(HourPassed::Event, 0x05979DF8)
DECLARE_EVENT_SOURCE_EX(HoursPassed::Event, 0x0597A7F0)
DECLARE_EVENT_SOURCE_EX(InstantReferenceInteractionEvent, 0x05978A08)
DECLARE_EVENT_SOURCE_EX(ItemConsumedEvent, 0x05978D28)
DECLARE_EVENT_SOURCE_EX(ItemCrafted::Event, 0x0597A158)
DECLARE_EVENT_SOURCE_EX(ItemSteal::Event, 0x0597A180)
DECLARE_EVENT_SOURCE_EX(ItemSwappedEvent, 0x05978CD8)
DECLARE_EVENT_SOURCE_EX(JailEscape::Event, 0x0597A1A8)
DECLARE_EVENT_SOURCE_EX(Jailing::Event, 0x0597A1D0)
DECLARE_EVENT_SOURCE_EX(LocationExplored::Event, 0x05977770)
DECLARE_EVENT_SOURCE_EX(LocationLinked::Event, 0x05977798)
DECLARE_EVENT_SOURCE_EX(LocationMarkerArrayUpdate::Event, 0x0597A220)
DECLARE_EVENT_SOURCE_EX(LocationTextEvent::Event, 0x05979CF8)
DECLARE_EVENT_SOURCE_EX(LockPickedEvent, 0x05978D00)
//DECLARE_EVENT_SOURCE_EX(MagicSystem::FlushLogEvent, 0x05839258)
//DECLARE_EVENT_SOURCE_EX(MagicSystem::LogEvent, 0x05839230)
DECLARE_EVENT_SOURCE_EX(MapMarkerDiscoveredEvent, 0x05978B20)
DECLARE_EVENT_SOURCE_EX(MissionMenuStateEvent::Event, 0x05979C80)
DECLARE_EVENT_SOURCE_EX(MurderCrime::Event, 0x05979F38)
DECLARE_EVENT_SOURCE_EX(ObjectScannedEvent, 0x05978AD0)
DECLARE_EVENT_SOURCE_EX(ObjectiveState::Event, 0x05978E90)
DECLARE_EVENT_SOURCE_EX(PiracyCrime::Event, 0x05979F60)
DECLARE_EVENT_SOURCE_EX(PlayerActiveEffectChanged::Event, 0x0597A450)
DECLARE_EVENT_SOURCE_EX(PlayerAddItemEvent, 0x05978940)
DECLARE_EVENT_SOURCE_EX(PlayerAmmoChanged::Event, 0x0597A248)
DECLARE_EVENT_SOURCE_EX(PlayerArrestedEvent, 0x05978B48)
DECLARE_EVENT_SOURCE_EX(PlayerAssaultActorEvent, 0x05978B70)
DECLARE_EVENT_SOURCE_EX(PlayerBuyShipEvent, 0x05978C60)
DECLARE_EVENT_SOURCE_EX(PlayerCrimeGoldEvent, 0x05978BC0)
DECLARE_EVENT_SOURCE_EX(PlayerDifficultySettingChanged::Event, 0x0597A270)
DECLARE_EVENT_SOURCE_EX(PlayerFailedPlotRouteEvent, 0x05977F90)
DECLARE_EVENT_SOURCE_EX(PlayerFastTravel::Event, 0x0597A360)
DECLARE_EVENT_SOURCE_EX(PlayerInDialogueChanged::Event, 0x0597A298)
DECLARE_EVENT_SOURCE_EX(PlayerJailEvent, 0x05978BE8)
DECLARE_EVENT_SOURCE_EX(PlayerLifeStateChanged::Event, 0x0597A2C0)
DECLARE_EVENT_SOURCE_EX(PlayerModifiedShipEvent, 0x05977FB8)
DECLARE_EVENT_SOURCE_EX(PlayerMurderActorEvent, 0x05978B98)
//DECLARE_EVENT_SOURCE_EX(PlayerNameEvent::NameChangedEvent, 0x058AF290)
DECLARE_EVENT_SOURCE_EX(PlayerPayFineEvent, 0x05978C10)
DECLARE_EVENT_SOURCE_EX(PlayerPickpocketSuccess::Event, 0x0597A478)
DECLARE_EVENT_SOURCE_EX(PlayerPlanetSurveyCompleteEvent, 0x05978A80)
DECLARE_EVENT_SOURCE_EX(PlayerPlanetSurveyProgressEvent, 0x05978AA8)
DECLARE_EVENT_SOURCE_EX(PlayerSellShipEvent, 0x05978C88)
DECLARE_EVENT_SOURCE_EX(PlayerTrespassEvent, 0x05978C38)
DECLARE_EVENT_SOURCE_EX(PoisonedWeapon::Event, 0x0597A2E8)
DECLARE_EVENT_SOURCE_EX(QuestStatus::Event, 0x05979338)
DECLARE_EVENT_SOURCE_EX(QuickContainerOpenedEvent, 0x05978A30)
//DECLARE_EVENT_SOURCE_EX(RadioManager::PipboyFrequencyDetectionEvent, 0x0584FB40)
//DECLARE_EVENT_SOURCE_EX(RadioManager::PipboyRadioTuningEvent, 0x0584FB90)
DECLARE_EVENT_SOURCE_EX(RadioManager::PipboyTransmitterDetectionEvent, 0x0591A328)
DECLARE_EVENT_SOURCE_EX(RefControlChangedEvent, 0x05978D78)
DECLARE_EVENT_SOURCE_EX(ReferenceDestroyedEvent, 0x059789E0)
DECLARE_EVENT_SOURCE_EX(RefillAliasEvent::Event, 0x05979310)
DECLARE_EVENT_SOURCE_EX(ReloadWeaponEvent::Event, 0x0597A010)
DECLARE_EVENT_SOURCE_EX(RolloverIsCrimeEvent::Event, 0x05979B60)
//DECLARE_EVENT_SOURCE_EX(ScannableUtils::ScannedEvent, 0x058AF100)
DECLARE_EVENT_SOURCE_EX(ShowSubtitleEvent::Event, 0x05979B88)
//DECLARE_EVENT_SOURCE_EX(SpaceshipEditor::TransactionEvent, 0x058A9EB8)
DECLARE_EVENT_SOURCE_EX(SpeechChallengeCompletionEvent, 0x05978AF8)
DECLARE_EVENT_SOURCE_EX(SpellsLearned::Event, 0x0597A040)
DECLARE_EVENT_SOURCE_EX(TESActivateEvent, 0x05977860)
DECLARE_EVENT_SOURCE_EX(TESActiveEffectApplyFinishEvent, 0x05977900)
DECLARE_EVENT_SOURCE_EX(TESActiveEffectRemovedEvent, 0x05977928)
DECLARE_EVENT_SOURCE_EX(TESActorActivatedRefEvent, 0x05977888)
DECLARE_EVENT_SOURCE_EX(TESActorLocationChangeEvent, 0x05977978)
DECLARE_EVENT_SOURCE_EX(TESBookReadEvent, 0x059779F0)
DECLARE_EVENT_SOURCE_EX(TESCellGravityChangeEvent, 0x05977B30)
DECLARE_EVENT_SOURCE_EX(TESCellNavmeshGeneratedEvent, 0x05977AB8)
DECLARE_EVENT_SOURCE_EX(TESCellReadyToApplyDecalsEvent, 0x05977AE0)
DECLARE_EVENT_SOURCE_EX(TESCellReferenceAttachDetachEvent, 0x05977A18)
DECLARE_EVENT_SOURCE_EX(TESCombatEvent, 0x05977B58)
DECLARE_EVENT_SOURCE_EX(TESCombatListEvent, 0x05977B80)
DECLARE_EVENT_SOURCE_EX(TESCommandModeCompleteCommandEvent, 0x05977DB0)
DECLARE_EVENT_SOURCE_EX(TESCommandModeEnterEvent, 0x05977DD8)
DECLARE_EVENT_SOURCE_EX(TESCommandModeExitEvent, 0x05977E00)
DECLARE_EVENT_SOURCE_EX(TESCommandModeGiveCommandEvent, 0x05977E28)
DECLARE_EVENT_SOURCE_EX(TESConsciousnessEvent, 0x05978620)
DECLARE_EVENT_SOURCE_EX(TESContainerChangedEvent, 0x05977BA8)
DECLARE_EVENT_SOURCE_EX(TESDeathEvent, 0x05977C70)
DECLARE_EVENT_SOURCE_EX(TESDeferredKillEvent, 0x05977C48)
DECLARE_EVENT_SOURCE_EX(TESDestructionStageChangedEvent, 0x05977CC0)
DECLARE_EVENT_SOURCE_EX(TESEnterBleedoutEvent, 0x05977CE8)
DECLARE_EVENT_SOURCE_EX(TESEnterSneakingEvent, 0x05977D38)
DECLARE_EVENT_SOURCE_EX(TESEquipEvent, 0x05977E50)
DECLARE_EVENT_SOURCE_EX(TESEscortWaitStartEvent, 0x05977D60)
DECLARE_EVENT_SOURCE_EX(TESEscortWaitStopEvent, 0x05977D88)
DECLARE_EVENT_SOURCE_EX(TESExitBleedoutEvent, 0x05977D10)
DECLARE_EVENT_SOURCE_EX(TESExitFurnitureEvent, 0x059778D8)
DECLARE_EVENT_SOURCE_EX(TESFormDeleteEvent, 0x05977EA0)
DECLARE_EVENT_SOURCE_EX(TESFormIDRemapEvent, 0x05977EC8)
DECLARE_EVENT_SOURCE_EX(TESFurnitureEvent, 0x05977EF0)
DECLARE_EVENT_SOURCE_EX(TESGrabReleaseEvent, 0x05977F18)
DECLARE_EVENT_SOURCE_EX(TESHarvestEvent::ItemHarvested, 0x05974870)
DECLARE_EVENT_SOURCE_EX(TESHitEvent, 0x05977F40)
DECLARE_EVENT_SOURCE_EX(TESInitScriptEvent, 0x05978008)
DECLARE_EVENT_SOURCE_EX(TESLimbCrippleEvent, 0x05978648)
DECLARE_EVENT_SOURCE_EX(TESLoadGameEvent, 0x05978080)
DECLARE_EVENT_SOURCE_EX(TESLocationExploredEvent, 0x05978030)
DECLARE_EVENT_SOURCE_EX(TESLockChangedEvent, 0x05978058)
DECLARE_EVENT_SOURCE_EX(TESMagicEffectApplyEvent, 0x059780A8)
DECLARE_EVENT_SOURCE_EX(TESMissionAcceptedEvent, 0x059781E8)
DECLARE_EVENT_SOURCE_EX(TESObjectLoadedEvent, 0x059780D0)
DECLARE_EVENT_SOURCE_EX(TESObjectREFRIsReadyForAttachEvent, 0x059780F8)
DECLARE_EVENT_SOURCE_EX(TESObjectREFRTranslationEvent, 0x059784B8)
DECLARE_EVENT_SOURCE_EX(TESOnPCDialogueTargetEvent, 0x05978698)
DECLARE_EVENT_SOURCE_EX(TESPackageEvent, 0x05978148)
DECLARE_EVENT_SOURCE_EX(TESPerkEntryRunEvent, 0x05978170)
DECLARE_EVENT_SOURCE_EX(TESPickNewIdleEvent, 0x05978670)
DECLARE_EVENT_SOURCE_EX(TESPickpocketFailedEvent, 0x05978198)
DECLARE_EVENT_SOURCE_EX(TESPlayerActiveEffectEvent, 0x05977950)
DECLARE_EVENT_SOURCE_EX(TESPlayerFollowerWarpEvent, 0x05977E78)
DECLARE_EVENT_SOURCE_EX(TESQuestInitEvent, 0x059781C0)
DECLARE_EVENT_SOURCE_EX(TESQuestRejectedEvent, 0x05978210)
DECLARE_EVENT_SOURCE_EX(TESQuestStageEvent, 0x05978238)
DECLARE_EVENT_SOURCE_EX(TESQuestStageItemDoneEvent, 0x05978260)
DECLARE_EVENT_SOURCE_EX(TESQuestStartStopEvent, 0x05978288)
DECLARE_EVENT_SOURCE_EX(TESQuestTimerEvent, 0x05978D50)
DECLARE_EVENT_SOURCE_EX(TESResetEvent, 0x059782D8)
DECLARE_EVENT_SOURCE_EX(TESResolveNPCTemplatesEvent, 0x05978300)
DECLARE_EVENT_SOURCE_EX(TESSceneActionEvent, 0x05978350)
DECLARE_EVENT_SOURCE_EX(TESScenePhaseEvent, 0x05978378)
DECLARE_EVENT_SOURCE_EX(TESSellEvent, 0x059783A0)
DECLARE_EVENT_SOURCE_EX(TESSleepStartEvent, 0x059783C8)
DECLARE_EVENT_SOURCE_EX(TESSleepStopEvent, 0x059783F0)
DECLARE_EVENT_SOURCE_EX(TESSpellCastEvent, 0x05978418)
DECLARE_EVENT_SOURCE_EX(TESSpellCastFailureEvent, 0x05978440)
DECLARE_EVENT_SOURCE_EX(TESSwitchRaceCompleteEvent, 0x059785F8)
DECLARE_EVENT_SOURCE_EX(TESTopicInfoEvent, 0x05978468)
DECLARE_EVENT_SOURCE_EX(TESTrackedStatsEvent, 0x05978490)
DECLARE_EVENT_SOURCE_EX(TESTrapHitEvent, 0x059784E0)
DECLARE_EVENT_SOURCE_EX(TESTriggerEnterEvent, 0x05978530)
DECLARE_EVENT_SOURCE_EX(TESTriggerEvent, 0x05978508)
DECLARE_EVENT_SOURCE_EX(TESTriggerLeaveEvent, 0x05978558)
//DECLARE_EVENT_SOURCE_EX(TESUnconsciousEvent, 0x058AE460)
DECLARE_EVENT_SOURCE_EX(TESWaitStartEvent, 0x059785A8)
DECLARE_EVENT_SOURCE_EX(TESWaitStopEvent, 0x059785D0)
DECLARE_EVENT_SOURCE_EX(TerminalHacked::Event, 0x0597A310)
DECLARE_EVENT_SOURCE_EX(TerminalMenuMenuItemRunEvent, 0x05977810)
DECLARE_EVENT_SOURCE_EX(TerminalMenuOnEnterEvent, 0x05977838)
DECLARE_EVENT_SOURCE_EX(TraitDiscoveryTextEvent::Event, 0x05979D20)
DECLARE_EVENT_SOURCE_EX(TravelMarkerStateChange::Event, 0x0597A3D8)
DECLARE_EVENT_SOURCE_EX(Trespass::Event, 0x0597A718)
DECLARE_EVENT_SOURCE_EX(TryUpdateShipHudTarget::Event, 0x05979CD0)
DECLARE_EVENT_SOURCE_EX(VATSCommand, 0x0597A778)
DECLARE_EVENT_SOURCE_EX(VATSEvents::ModeChange, 0x0597A750)
//DECLARE_EVENT_SOURCE_EX(VehicleAmmoChanged::Event, 0x058AF9E8)
DECLARE_EVENT_SOURCE_EX(WeaponAttack::Event, 0x0597A338)
DECLARE_EVENT_SOURCE_EX(WeaponFiredEvent, 0x0590A240)
//DECLARE_EVENT_SOURCE_EX(WorkbenchTracking::TrackingStatusChanged::Event, 0x058AF3E0)
DECLARE_EVENT_SOURCE_EX(WorkshopNPCTransferEvent, 0x05977FE0)
DECLARE_EVENT_SOURCE_EX(XPChange::Event, 0x0591B8E0)
//DECLARE_EVENT_SOURCE_EX(nsBarterMenu::CompletedEvent, 0x058AF380)
