using UnityEngine;
using UnityEngine.UI;

public class TankShooting : MonoBehaviour
{
    public int m_PlayerNumber = 1;       
    public Rigidbody m_Shell;            
    public Transform m_FireTransform;    
    public Slider m_AimSlider;           
    public AudioSource m_ShootingAudio;  
    public AudioClip m_ChargingClip;     
    public AudioClip m_FireClip;         
    public float m_MinLaunchForce = 15f; 
    public float m_MaxLaunchForce = 30f; 
    public float m_MaxChargeTime = 0.75f;

    
    private string m_FireButton;         
    private float m_CurrentLaunchForce;  
    private float m_ChargeSpeed;         
    private bool m_Fired;                


    private void OnEnable()
    {
        m_CurrentLaunchForce = m_MinLaunchForce;
        m_AimSlider.value = m_MinLaunchForce;
    }


    private void Start()
    {
        m_FireButton = "Fire" + m_PlayerNumber;

        m_ChargeSpeed = (m_MaxLaunchForce - m_MinLaunchForce) / m_MaxChargeTime;
    }
    

    private void Update()
    {
        // Track the current state of the fire button and make decisions based on the current launch force.
        m_AimSlider.value = m_MinLaunchForce;

        // if the force exceeds the max and not fired yet
        if (m_CurrentLaunchForce >= m_MaxLaunchForce && !m_Fired)
        {
            // use the max launch force instead
            m_CurrentLaunchForce = m_MaxLaunchForce;
            Fire();
        }

        // if the fire button has just started being pressed
        else if(Input.GetButtonDown(m_FireButton))
        {
            // reset
            m_Fired = false;
            m_CurrentLaunchForce = m_MinLaunchForce;

            // change the clip to charging
            m_ShootingAudio.clip = m_ChargingClip;
            m_ShootingAudio.Play();
        }

        // if the fire button is being held and the shell not fired yet
        else if (Input.GetButton(m_FireButton) && !m_Fired)
        {
            // increment the launch force and update the slider
            m_CurrentLaunchForce += m_ChargeSpeed * Time.deltaTime;
            m_AimSlider.value = m_CurrentLaunchForce;
        }

        // if the fire button released and the shell hasn't be launched yet
        else if (Input.GetButtonUp(m_FireButton) && !m_Fired)
        {
            // just fire launch the shell
            Fire();
        }
    }


    private void Fire()
    {
        // Instantiate and launch the shell.

        // set the fired flag to true
        m_Fired = true;

        // create a shell instance and save it as rigidbody
        Rigidbody shellInstance = Instantiate(m_Shell, m_FireTransform.position, m_FireTransform.rotation) as Rigidbody;

        // Set the shell's velocity to the launch force in the fire position's forward direction.
        shellInstance.velocity = m_CurrentLaunchForce * m_FireTransform.forward;

        // change clip to firing
        m_ShootingAudio.clip = m_FireClip;
        m_ShootingAudio.Play();

        // Reset the launch force.  This is a precaution in case of missing button events.
        m_CurrentLaunchForce = m_MinLaunchForce;
    }
}