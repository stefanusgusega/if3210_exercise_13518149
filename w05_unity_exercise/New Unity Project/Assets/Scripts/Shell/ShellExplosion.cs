using UnityEngine;

public class ShellExplosion : MonoBehaviour
{
    public LayerMask m_TankMask; // Used to filter what the explosion affects, this should be set to "Players".
    public ParticleSystem m_ExplosionParticles; // Reference to the particles that will play on explosion.      
    public AudioSource m_ExplosionAudio;  // Reference to the audio that will play on explosion.            
    public float m_MaxDamage = 100f;                  
    public float m_ExplosionForce = 1000f;            
    public float m_MaxLifeTime = 2f;                  
    public float m_ExplosionRadius = 5f;              


    private void Start()
    {
        // If it isn't destroyed by then, destroy the shell after it's lifetime.

        // destroy the bullet if reaching the max life time
        Destroy(gameObject, m_MaxLifeTime);
    }


    private void OnTriggerEnter(Collider other)
    {
        // Find all the tanks in an area around the shell and damage them.

        // Collect all the colliders in a sphere from the shell's current position to a radius of the explosion radius.
        Collider[] colliders = Physics.OverlapSphere(transform.position, m_ExplosionRadius, m_TankMask);

        for (int i=0; i < colliders.Length; i++)
        {
            Rigidbody targetRigidbody = colliders[i].GetComponent<Rigidbody>();
            if (!targetRigidbody) continue;
            targetRigidbody.AddExplosionForce(m_ExplosionForce, transform.position, m_ExplosionRadius);

            TankHealth targetHealth = targetRigidbody.GetComponent<TankHealth>();

            if (!targetHealth) continue;

            float damage = CalculateDamage(targetRigidbody.position);

            targetHealth.TakeDamage(damage);

            m_ExplosionParticles.transform.parent = null;

            m_ExplosionParticles.Play();

            m_ExplosionAudio.Play();

            Destroy(m_ExplosionParticles.gameObject, m_ExplosionParticles.main.duration);

            // Destroy the shell.
            Destroy(gameObject);

        }

    }


    private float CalculateDamage(Vector3 targetPosition)
    {
        // Calculate the amount of damage a target should take based on it's position.
        // create a vector
        Vector3 explosionToTarget = targetPosition - transform.position;

        // distance as magnitude
        float explosionDistance = explosionToTarget.magnitude;

        float relDistance = (m_ExplosionRadius - explosionDistance) / m_ExplosionRadius;

        float damage = relDistance * m_MaxDamage;

        damage = Mathf.Max(0f, damage);
        return damage;
    }
}